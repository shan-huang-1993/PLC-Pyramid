"""
train.py: train Programming Language Correction model

Usage:
   train.py --train-src=<file> --train-tgt=<file> --dev-src=<file> --dev-tgt=<file> --vocab=<file> [options]

Options:
    -h --help                               show this screen.
    --cuda=<int>                            use GPU number #
    --train-src=<file>                      train source file
    --train-tgt=<file>                      train target file
    --dev-src=<file>                        dev source file
    --dev-tgt=<file>                        dev target file
    --vocab=<file>                          vocab file
    --seed=<int>                            seed [default: 0]
    --batch-size=<int>                      batch size [default: 8]
    --input-length=<int>                    maximum input length [default: 500]
    --embed-size=<int>                      embedding size [default: 400]
    --enc-hidden=<int>                      encode hidden size (for GRU models only) [default: 400]
    --att-size=<int>                        attention size (for GRU models only) [default: 400]
    --dec-hidden=<int>                      decode hidden size (for GRU models only) [default: 400]
    --d-model=<int>                         size of attention vectors (for Transformer models only) [default: 512]
    --num-heads=<int>                       number of attention heads in multihead attention (for Transformer models only) [default: 8]
    --enc-layer=<int>                       number of encoder layers [default: 3]
    --dec-layer=<int>                       number of decoder layers [default: 3]
    --clip-grad=<float>                     gradient clipping [default: 5.0]
    --log-every=<int>                       log every [default: 600]
    --max-epoch=<int>                       max epoch [default: 30]
    --patience=<int>                        wait for how many iterations to decay learning rate [default: 5]
    --max-num-trial=<int>                   terminate training after how many trials [default: 5]
    --lr-decay=<float>                      learning rate decay [default: 0.5]
    --beam-size=<int>                       beam size [default: 5]
    --sample-size=<int>                     sample size [default: 5]
    --lr=<float>                            initial learning rate [default: 0.0003]
    --beta1=<float>                         beta1 parameter of Adam Optimizer [default: 0.9]
    --beta2=<float>                         beta2 parameter of Adam Optimizer [default: 0.98]
    --uniform-init=<float>                  uniformly initialize all parameters [default: 0.1]
    --save-to=<file>                        model save path [default: model.bin]
    --valid-niter=<int>                     perform validation after how many iterations [default: 3000]
    --dropout=<float>                       dropout [default: 0.15]
    --model-path=<file>                     model to load 
    --log-path=<file>                       log file [default: train_log.txt]
    --pyramid=<int>                         use pyramid structure [default: 0]
    --model-type=<str>                      use model type and attention type, options are Bahdanau, general, concat, dot, Transformer [default: Bahdanau]
"""

import math
import sys
import pickle
import time

import torch
from docopt import docopt
import numpy as np
from typing import List, Tuple, Dict, Set, Union
import torch.nn.functional as F

from PLC_Model.utils import create_src_mask, create_tgt_mask, read_corpus, batch_iter
from PLC_Model.Vocab_word import Vocab
from PLC_Model.GRU import GRU
from PLC_Model.TFM import Transformer

def evaluate_ppl_GRU(model, dev_data, batch_size=32):
    was_training = model.training
    model.eval()
    
    cum_loss = 0.
    cum_tgt_words = 0.
    
    with torch.no_grad():
        for src_sents, tgt_sents in batch_iter(dev_data, batch_size):
            loss = model(src_sents, tgt_sents).sum()
            
            cum_loss += loss.item()
            tgt_word_num_to_predict = sum(len(s[1:]) for s in tgt_sents)
            cum_tgt_words += tgt_word_num_to_predict
            
        ppl = np.exp(cum_loss/cum_tgt_words)
        
    if was_training:
        model.train()
        
    return ppl

def evaluate_ppl_TFM(model, input_length, dev_data, vocab, device, batch_size=32):
    was_training = model.training
    model.eval()
    
    cum_loss = 0.
    cum_tgt_words = 0.
    
    with torch.no_grad():
        for src_sents, tgt_sents in batch_iter(dev_data, batch_size):
            
            src = vocab.to_input_tensor(src_sents, input_length, device = device)
            tgt = vocab.to_input_tensor(tgt_sents, input_length, device = device)
            src_mask = create_src_mask(src, vocab['<pad>'], device = device)
            
            tgt_input = tgt[:, :-1]
            tgt_mask = create_tgt_mask(tgt_input, vocab['<pad>'], device = device)
            tgt_output = tgt[:, 1:].contiguous().view(-1)
            
            preds = model(src, tgt_input, src_mask, tgt_mask)
            loss = F.cross_entropy(preds.view(-1, preds.size(-1)), tgt_output, ignore_index=vocab['<pad>'], reduction = 'sum')
            
            cum_loss += loss.item()
            tgt_word_num_to_predict = sum(len(s[1:]) for s in tgt_sents)
            cum_tgt_words += tgt_word_num_to_predict
            
        ppl = np.exp(cum_loss/cum_tgt_words)
        
    if was_training:
        model.train()
        
    return ppl
    
def train(args: Dict):
    if args['--model-path'] : 
        continue_training = True
    else:
        continue_training = False
    
    log_file = open(args['--log-path'], 'a') 
    # You can choose where to output the training log
    output_dests = [sys.stderr, log_file]
    
    train_batch_size = int(args['--batch-size'])
    clip_grad = float(args['--clip-grad'])
    log_every = int(args['--log-every'])
    model_save_path = args['--save-to']
    valid_niter = int(args['--valid-niter'])
    
    pyramid = bool(int(args['--pyramid']))
    model_type = args['--model-type']
    
    vocab = Vocab(args['--vocab'])
    
    if continue_training: 
        if model_type in ["Bahdanau", "dot", "general", "concat"]:
            model = GRU.load(args['--model-path'], vocab)
    else:
        if model_type in ["Bahdanau", "dot", "general", "concat"]:
            model = GRU(input_length=int(args['--input-length']),
                        embed_size=int(args['--embed-size']),
                        enc_hidden_size=int(args['--enc-hidden']),
                        dec_hidden_size=int(args['--dec-hidden']),
                        attention_size=int(args['--att-size']),
                        vocab=vocab,
                        enc_layers = int(args['--enc-layer']),
                        dec_layers = int(args['--dec-layer']),
                        dropout_rate=float(args['--dropout']),
                        pyramid = pyramid,
                        attention_type = model_type)
            evaluate_ppl = evaluate_ppl_GRU
        else:
            model = Transformer(max_enc_len = int(args['--input-length']),
                        max_dec_len = int(args['--input-length']) - 1,
                        vocab = vocab,
                        d_model = int(args['--d-model']),
                        enc_layers = int(args['--enc-layer']),
                        dec_layers = int(args['--dec-layer']),
                        heads = int(args['--num-heads']),
                        dropout = float(args['--dropout']),
                        pyramid = pyramid)
            evaluate_ppl = evaluate_ppl_TFM
            
        uniform_init = float(args['--uniform-init'])
        if np.abs(uniform_init) > 0.:
            for dest in output_dests:
                print('uniformly initialize parameters[-%f, +%f]' % (uniform_init, uniform_init), file=dest)
            for p in model.parameters():
                p.data.uniform_(-uniform_init, uniform_init)
                
    train_data_src = read_corpus(args['--train-src'], int(args['--input-length']))
    train_data_tgt = read_corpus(args['--train-tgt'], int(args['--input-length']))
    
    dev_data_src = read_corpus(args['--dev-src'], int(args['--input-length']))
    dev_data_tgt = read_corpus(args['--dev-tgt'], int(args['--input-length']))
    
    train_data = list(zip(train_data_src, train_data_tgt))
    dev_data = list(zip(dev_data_src, dev_data_tgt))
    
    if args['--cuda']:        
        device = torch.device("cuda:" + str(args['--cuda']))
    else:
        device = torch.device("cpu")
    for dest in output_dests:
        print('use device: %s' % device, file=dest)
    
    model = model.to(device)
    model.train()
    
    if continue_training:
        optimizer_state_dict = torch.load(args['--model-path'] + '.optim')
        optimizer = torch.optim.Adam(model.parameters())
        optimizer.load_state_dict(optimizer_state_dict)
    else:
        optimizer = torch.optim.Adam(model.parameters(), lr=float(args['--lr']), betas = (float(args['--beta1']), float(args['--beta2'])))
    num_trial = 0
    train_iter = patience = cum_loss = report_loss = cum_tgt_words = report_tgt_words = 0
    cum_examples = report_examples = epoch = valid_num = 0
    hist_valid_scores = []
    train_time = begin_time = time.time()
    for dest in output_dests:
        print('begin Maximum Likelihood training', file = dest)
    
    while True:
        epoch += 1
        
        for src_sents, tgt_sents in batch_iter(train_data, batch_size=train_batch_size, shuffle=True):
            train_iter += 1
            batch_size = len(src_sents)
            
            if model_type == 'Transformer':
                src = vocab.to_input_tensor(src_sents, int(args['--input-length']), device = device)
                tgt = vocab.to_input_tensor(tgt_sents, int(args['--input-length']), device = device)
                src_mask = create_src_mask(src, vocab['<pad>'], device = device)
            
                tgt_input = tgt[:, :-1]
                tgt_mask = create_tgt_mask(tgt_input, vocab['<pad>'], device = device)
                tgt_output = tgt[:, 1:].contiguous().view(-1)
                
                preds = model(src, tgt_input, src_mask, tgt_mask)
                loss = F.cross_entropy(preds.view(-1, preds.size(-1)), tgt_output, ignore_index=vocab['<pad>'], reduction = 'sum')

                optimizer.zero_grad()
                batch_loss = loss.item()
                
            else:
                example_losses = model(src_sents, tgt_sents) # (batch_size,)
                batch_loss = example_losses.sum()
                
                optimizer.zero_grad()
                loss = batch_loss
                batch_loss = batch_loss.item()
                
            loss.backward()
            
            grad_norm = torch.nn.utils.clip_grad_norm_(model.parameters(), clip_grad)
            
            optimizer.step()
            
            report_loss += batch_loss
            cum_loss += batch_loss
            
            tgt_words_num_to_predict = sum(len(s[1:]) for s in tgt_sents)  # omitting leading `<s>`
            report_tgt_words += tgt_words_num_to_predict
            cum_tgt_words += tgt_words_num_to_predict
            report_examples += batch_size
            cum_examples += batch_size
            
            if train_iter % log_every == 0:
                for dest in output_dests:
                    print('epoch %d, iter %d, avg. loss %.2f, avg. ppl %.2f ' \
                          'cum. examples %d, speed %.2f words/sec, time elapsed %.2f sec' % (epoch, train_iter,
                                                                                             report_loss / report_examples,
                                                                                             math.exp(report_loss / report_tgt_words),
                                                                                             cum_examples,
                                                                                             report_tgt_words / (time.time() - train_time),
                                                                                             time.time() - begin_time), file=dest)
                train_time = time.time()
                report_loss = report_tgt_words = report_examples = 0.
                
            if train_iter % valid_niter == 0:
                for dest in output_dests:
                    print('epoch %d, iter %d, cum. loss %.2f, cum. ppl %.2f cum. examples %d' % (epoch, train_iter,
                                                                                             cum_loss / cum_examples,
                                                                                             np.exp(cum_loss / cum_tgt_words),
                                                                                             cum_examples), file=dest)

                cum_loss = cum_examples = cum_tgt_words = 0.
                valid_num += 1
                
                print('begin validation ...', file=sys.stderr)
                if model_type in ["Bahdanau", "dot", "general", "concat"]:
                    dev_ppl = evaluate_ppl(model, dev_data, batch_size=128)   # dev batch size can be a bit larger
                else:
                    dev_ppl = evaluate_ppl(model, int(args['--input-length']), dev_data, vocab = vocab, device = device, batch_size=128)
                
                valid_metric = -dev_ppl
                
                for dest in output_dests:
                    print('validation: iter %d, dev. ppl %f' % (train_iter, dev_ppl), file=dest)
                    
                is_better = len(hist_valid_scores) == 0 or valid_metric > max(hist_valid_scores)
                hist_valid_scores.append(valid_metric)
                
                if is_better:
                    patience = 0
                    for dest in output_dests:
                        print('save currently the best model to [%s]' % model_save_path, file=dest)
                    model.save(model_save_path)
                    
                    torch.save(optimizer.state_dict(), model_save_path + '.optim')
                    
                elif patience < int(args['--patience']):
                    patience += 1
                    
                    for dest in output_dests:
                        print('hit patience %d' % patience, file=dest)

                    if patience >= int(args['--patience']):
                        num_trial += 1
                        
                        for dest in output_dests:
                            print('hit #%d trial' % num_trial, file=dest)
                            
                        if num_trial >= int(args['--max-num-trial']):
                            for dest in output_dests:
                                print('early stop!', file=dest)
                            log_file.close()
                            exit(0)
                            
                        lr = optimizer.param_groups[0]['lr'] * float(args['--lr-decay'])
                        
                        for dest in output_dests:
                            print('load previously best model and decay learning rate to %f' % lr, file=dest)
                            
                        params = torch.load(model_save_path, map_location=lambda storage, loc: storage)
                        model.load_state_dict(params['state_dict'])
                        model = model.to(device)
                            
                        for dest in output_dests:
                            print('restore parameters of the optimizers', file=dest)
                            
                        optimizer.load_state_dict(torch.load(model_save_path + '.optim'))
                        for param_group in optimizer.param_groups:
                            param_group['lr'] = lr
                                
                        patience = 0
                        
                if epoch >= int(args['--max-epoch']):
                    for dest in output_dests:
                        print('reached maximum number of epochs!', file=dest)
                    log_file.close()
                    exit(0)
                        
def main():
    args = docopt(__doc__)
    log_file = open(args['--log-path'], 'w+')
    print(args, file = log_file)
    log_file.close()
    seed = int(args['--seed'])
    torch.manual_seed(seed)
    if args['--cuda']:
        torch.cuda.manual_seed(seed)
    np.random.seed(seed * 11 // 7)
    
    train(args)
    
if __name__ == '__main__':
    main()

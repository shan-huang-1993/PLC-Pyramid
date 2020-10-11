"""
run.py: Run Script for Simple NMT Model

Usage:
    run.py train --train=<file> --dev=<file> [options]

Options:
    -h --help                               show this screen.
    --cuda=<int>                            use GPU number
    --train=<file>                          train file
    --dev=<file>                            dev file
    --vocab=<file>                          vocab file
    --seed=<int>                            seed [default: 0]
    --batch-size=<int>                      batch size [default: 32]
    --input-length=<int>                    maximum input length [default: 304]
    --num-classes=<int>                     number of classes to classify [default: 44]
    --model-path=<file>                     model to load 
    --log-path=<file>                       log file [default: train_log.txt]
    --log-every=<int>                       log every [default: 10]
    --max-epoch=<int>                       max epoch [default: 100]
    --patience=<int>                        wait for how many iterations to decay learning rate [default: 10]
    --max-num-trial=<int>                   terminate training after how many trials [default: 5]
    --save-to=<file>                        model save path [default: model.bin]
    --valid-niter=<int>                     perform validation after how many iterations [default: 50]
    --d-model=<int>                         size of attention vectors [default: 512]
    --enc-layers=<int>                      number of encoder layers [default: 6]
    --dec-layers=<int>                      number of decoder layers [default: 6]
    --num-heads=<int>                       number of attention heads in multihead attention [default: 8]
    --lr=<float>                            learning rate [default: 0.0003]
    --uniform-init=<float>                  uniformly initialize all parameters [default: 0.1]
    --clip-grad=<float>                     gradient clipping [default: 5.0]
    --dropout=<float>                       dropout [default: 0.15]
"""
import math
import sys
import pickle
import time

import torch
import torch.nn as nn
from docopt import docopt
import numpy as np
from typing import List, Tuple, Dict, Set, Union
import torch.nn.functional as F
from utils_model import Reinit, ExpandVocab

from utils import create_src_mask, create_tgt_mask, read_corpus, batch_iter 
from model_TFM import Transformer
from Vocab_word import Vocab
from TFM_Classify import TFMClassifier

def validation(model, input_length, dev_data, vocab, device, batch_size=32):
    was_training = model.training
    model.eval()
    
    cum_examples = 0
    cum_correct = 0
    
    with torch.no_grad():
        for src_sents, labels in batch_iter(dev_data, batch_size):
            src = vocab.to_input_tensor(src_sents, input_length, device = device)
            dec_init = torch.tensor([[vocab['<sos>']] for i in range(len(labels))])
            src_mask = create_src_mask(src, vocab['<pad>'], device = device)
            cum_examples += len(labels)
            
            P = model(src, dec_init, src_mask)
            label_pres = torch.argmax(P, dim = -1)
            for i in range(len(label_pres)):
                if label_pres[i] == labels[i]:
                    cum_correct += 1
        
    if was_training:
        model.train()
        
    return cum_correct/cum_examples
    

def train(args):
    if args['--model-path'] : 
        continue_training = True
    else:
        continue_training = False
    
    log_file = open(args['--log-path'], 'a')
    
    train_data_src, train_data_label = read_corpus(args['--train'])
    dev_data_src, dev_data_label = read_corpus(args['--dev'])
    train_data = list(zip(train_data_src, train_data_label))
    dev_data = list(zip(dev_data_src, dev_data_label))
    
    train_batch_size = int(args['--batch-size'])
    clip_grad = float(args['--clip-grad'])
    log_every = int(args['--log-every'])
    model_save_path = args['--save-to']
    valid_niter = int(args['--valid-niter'])
    
    vocab_old = Vocab('vocab_old.txt')
    vocab = Vocab('vocab_total.txt')
    
    if args['--cuda'] is not None:        
        device = torch.device("cuda:" + str(args['--cuda']))
    else:
        device = torch.device("cpu")
    print('use device: %s' % device, file=sys.stderr)
    print('use device: %s' % device, file=log_file)
    
    '''
    if continue_training: 
        model = Transformer.load(args['--model-path'], vocab)
    else:
        model = Transformer(max_enc_len = int(args['--input-length']),
                            max_dec_len = int(args['--input-length']) - 1,
                            vocab = vocab,
                            d_model = int(args['--d-model']),
                            enc_layers = int(args['--enc-layers']),
                            dec_layers = int(args['--dec-layers']),
                            heads = int(args['--num-heads']),
                            dropout = float(args['--dropout']),
                            device = device)
        uniform_init = float(args['--uniform-init'])
        if np.abs(uniform_init) > 0.:
            print('uniformly initialize parameters[-%f, +%f]' % (uniform_init, uniform_init), file=sys.stderr)
            print('uniformly initialize parameters[-%f, +%f]' % (uniform_init, uniform_init), file=log_file)
            for p in model.parameters():
                p.data.uniform_(-uniform_init, uniform_init)
    '''
    
    model1 = Transformer.load(args['--model-path'], vocab_old)
    model1.eval()
    model1 = ExpandVocab(model1, vocab_old, vocab)               
    model1 = Reinit(model1)
    model = TFMClassifier(max_enc_len = int(args['--input-length']),
                        vocab = vocab,
                        d_model = int(args['--d-model']),
                        enc_layers = int(args['--enc-layers']),
                        dec_layers = int(args['--dec-layers']),
                        heads = int(args['--num-heads']),
                        num_classes = int(args['--num-classes']),
                        dropout = float(args['--dropout']),
                        device = device)
    model.encoder = model1.encoder
    model.train()
    
    model.device = device
    model = model.to(device)
    CELoss = nn.CrossEntropyLoss(reduction = 'sum').to(device)
    
    '''
    if continue_training:
        optimizer_state_dict = torch.load(args['--model-path'] + '.optim')
        optimizer = torch.optim.Adam(model.parameters())
        optimizer.load_state_dict(optimizer_state_dict)
    else:
        optimizer = torch.optim.Adam(model.parameters(), lr=float(args['--lr']), betas = (0.9, 0.98))
    '''
    
    optimizer = torch.optim.Adam(model.parameters(), lr=float(args['--lr']), betas = (0.9, 0.98))
    num_trial = 0
    
    train_iter = patience = cum_loss = report_loss = cum_tgt_words = report_tgt_words = 0
    cum_examples = report_examples = epoch = valid_num = 0
    hist_valid_scores = []
    train_time = begin_time = time.time()
    print('begin Maximum Likelihood training', file = sys.stderr)
    print('begin Maximum Likelihood training', file = log_file)
    
    log_file.close()
    
    while True:
        epoch += 1
        
        for src_sents, labels in batch_iter(train_data, batch_size=train_batch_size, shuffle=True):
            batch_size = len(labels)
            labels = torch.tensor(labels, device = device)
            train_iter += 1
            src = vocab.to_input_tensor(src_sents, int(args['--input-length']), device = device)
            dec_init = torch.tensor([[vocab['<sos>']] for i in range(len(labels))])
            src_mask = create_src_mask(src, vocab['<pad>'], device = device)
            
            P = model(src, dec_init, src_mask)
            P = P.squeeze(1)
            batch_loss = CELoss(P, labels)
            loss = batch_loss / batch_size
            
            loss.backward()
            
            grad_norm = torch.nn.utils.clip_grad_norm_(model.parameters(), clip_grad)
            
            optimizer.step()
            
            cum_examples += len(src_sents)
            batch_loss_val = batch_loss.item()
            report_loss += batch_loss_val
            cum_loss += batch_loss_val
            
            report_examples += batch_size
            cum_examples += batch_size
            
            if train_iter % log_every == 0:
                log_file = open(args['--log-path'], 'a')
                
                print('epoch %d, iter %d, avg. loss %.2f, ' \
                      'cum. examples %d, speed %.2f examples/sec, time elapsed %.2f sec' % (epoch, train_iter,
                                                                                         report_loss / report_examples,
                                                                                         cum_examples,
                                                                                         report_examples / (time.time() - train_time),
                                                                                         time.time() - begin_time), file=sys.stderr)
                print('epoch %d, iter %d, avg. loss %.2f, ' \
                      'cum. examples %d, speed %.2f examples/sec, time elapsed %.2f sec' % (epoch, train_iter,
                                                                                         report_loss / report_examples,
                                                                                         cum_examples,
                                                                                         report_examples / (time.time() - train_time),
                                                                                         time.time() - begin_time), file=log_file)
                train_time = time.time()
                report_loss = report_tgt_words = report_examples = 0.
                log_file.close()
                
            if train_iter % valid_niter == 0:
                log_file = open(args['--log-path'], 'a')
                print('epoch %d, iter %d, cum. loss %.2f, cum. examples %d' % (epoch, train_iter,
                                                                               cum_loss / cum_examples,
                                                                               cum_examples), file=sys.stderr)
                print('epoch %d, iter %d, cum. loss %.2f, cum. examples %d' % (epoch, train_iter,
                                                                               cum_loss / cum_examples,
                                                                               cum_examples), file=log_file)        
            
                cum_loss = cum_examples = cum_tgt_words = 0.
                valid_num += 1

                print('begin validation ...', file=sys.stderr)
                print('begin validation ...', file=log_file)
                accuracy = validation(model, input_length = int(args['--input-length']), dev_data = dev_data, vocab = vocab, device = device, batch_size=64)   # dev batch size can be a bit larger
                valid_metric = accuracy
                
                print('validation: iter %d, dev. accuracy %.3f' % (train_iter, accuracy), file=sys.stderr)
                print('validation: iter %d, dev. accuracy %.3f' % (train_iter, accuracy), file=log_file)
            
                is_better = len(hist_valid_scores) == 0 or valid_metric > max(hist_valid_scores)
                hist_valid_scores.append(valid_metric)
            
                if is_better:
                    patience = 0
                    print('save currently the best model to [%s]' % model_save_path, file=sys.stderr)
                    print('save currently the best model to [%s]' % model_save_path, file=log_file)
                    model.save(model_save_path)
                
                    torch.save(optimizer.state_dict(), model_save_path + '.optim')
                
                elif patience < int(args['--patience']):
                    patience += 1
                    print('hit patience %d' % patience, file=sys.stderr)
                    print('hit patience %d' % patience, file=log_file)

                    if patience >= int(args['--patience']):
                        print('early stop!', file=sys.stderr)
                        print('early stop!', file=log_file)
                        log_file.close()
                        exit(0)
                        '''
                        num_trial += 1
                        print('hit #%d trial' % num_trial, file=sys.stderr)
                        print('hit #%d trial' % num_trial, file=log_file)
                        
                        if num_trial >= int(args['--max-num-trial']):
                            print('early stop!', file=sys.stderr)
                            print('early stop!', file=log_file)
                            log_file.close()
                            exit(0)
                        
                            lr = optimizer.param_groups[0]['lr'] * float(args['--lr-decay'])
                            print('load previously best model and decay learning rate to %f' % lr, file=sys.stderr)
                            print('load previously best model and decay learning rate to %f' % lr, file=log_file)
                        
                            params = torch.load(model_save_path, map_location=lambda storage, loc: storage)
                            model.load_state_dict(params['state_dict'])
                            model = model.to(device)
                        
                            print('restore parameters of the optimizers', file=sys.stderr)
                            print('restore parameters of the optimizers', file=log_file)
                            optimizer.load_state_dict(torch.load(model_save_path + '.optim'))
                        
                            for param_group in optimizer.param_groups:
                                param_group['lr'] = lr
                            
                            patience = 0
                        '''
                    if epoch >= int(args['--max-epoch']):
                        print('reached maximum number of epochs!', file=sys.stderr)
                        print('reached maximum number of epochs!', file=log_file)
                        log_file.close()
                        exit(0)
                log_file.close()
            
def main():
    args = docopt(__doc__)
    log_file = open(args['--log-path'], 'w+')
    print(args, file = log_file)
    log_file.close()
    seed = int(args['--seed'])
    torch.manual_seed(seed)
    if args['--cuda']:
        torch.cuda.manual_seed(seed)
    np.random.seed(seed * 13 // 7)
    
    if args['train']:
        train(args)
    
if __name__ == '__main__':
    main()
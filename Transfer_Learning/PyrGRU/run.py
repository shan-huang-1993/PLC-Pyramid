"""
run.py: Run Script for Simple NMT Model

Usage:
    run.py train --train=<file> --dev=<file> [options]

Options:
    -h --help                               show this screen.
    --cuda=<int>                            use GPU number
    --train=<file>                          train file
    --dev=<file>                            dev sfile
    --vocab=<file>                          vocab file
    --seed=<int>                            seed [default: 0]
    --batch-size=<int>                      batch size [default: 16]
    --input-length=<int>                    maximum input length [default: 304]
    --embed-size=<int>                      embedding size [default: 400]
    --enc-hidden=<int>                      encode hidden size [default: 400]
    --att-size=<int>                        attention size [default: 400]
    --ff-size=<int>                         feedforward layer size [default: 2048]
    --num-class=<int>                       number of classes [default: 44]
    --clip-grad=<float>                     gradient clipping [default: 5.0]
    --log-every=<int>                       log every [default: 10]
    --max-epoch=<int>                       max epoch [default: 30]
    --input-feed                            use input feeding
    --patience=<int>                        wait for how many iterations to decay learning rate [default: 10]
    --max-num-trial=<int>                   terminate training after how many trials [default: 1]
    --lr-decay=<float>                      learning rate decay [default: 0.5]
    --lr=<float>                            learning rate [default: 0.0003]
    --uniform-init=<float>                  uniformly initialize all parameters [default: 0.1]
    --save-to=<file>                        model save path [default: model.bin]
    --valid-niter=<int>                     perform validation after how many iterations [default: 50]
    --dropout=<float>                       dropout [default: 0.15]
    --max-decoding-time-step=<int>          maximum number of decoding time steps [default: 70]
    --model-path=<file>                     model to load 
    --log-path=<file>                       log file [default: train_log.txt]
"""

import math
import sys
import pickle
import time

import torch
from docopt import docopt
import numpy as np
from typing import List, Tuple, Dict, Set, Union
from utils import read_corpus, batch_iter
from Vocab_word import Vocab
from NLC import NLC
from Classification import Classification
import torch.nn as nn

def validation(model, dev_data, batch_size=32):
    was_training = model.training
    model.eval()
    #cum_examples = 0
    #cum_correct = 0
    cum_loss = 0
    
    CELoss = nn.CrossEntropyLoss(reduction = 'sum')
    with torch.no_grad():
        for src_sents, labels in batch_iter(dev_data, batch_size):
            labels = torch.tensor(labels)
            #cum_examples += len(src_sents)
            P = model(src_sents)
            cum_loss += CELoss(P, labels)
            #label_pres = torch.argmax(P, dim = -1)
            #for i in range(len(label_pres)):
            #    if label_pres[i] == labels[i]:
            #        cum_correct += 1
            
    if was_training:
        model.train()
        
    #return cum_correct/cum_examples
    return -cum_loss
    
def train(args: Dict):
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
    
    vocab = Vocab('vocab_total.txt')
    vocab_old = Vocab('vocab_old.txt')
    
    model = Classification(input_length=int(args['--input-length']),
                num_class=int(args['--num-class']),
                embed_size=int(args['--embed-size']),
                enc_hidden_size=int(args['--enc-hidden']),
                attention_size=int(args['--att-size']),
                ff_size = int(args['--ff-size']),
                vocab=vocab,
                dropout_rate=float(args['--dropout']))
    uniform_init = float(args['--uniform-init'])
    if np.abs(uniform_init) > 0.:
        print('uniformly initialize parameters[-%f, +%f]' % (uniform_init, uniform_init), file=sys.stderr)
        print('uniformly initialize parameters[-%f, +%f]' % (uniform_init, uniform_init), file=log_file)
        for p in model.parameters():
            p.data.uniform_(-uniform_init, uniform_init)

    enc_layers = 3
##### For Transfer Learning ####                
    if continue_training:
        model2 = NLC.load(args['--model-path'], vocab_old)
        model.eval()
        for i in range(enc_layers - 1):
            model.encoder_GRU[i].weight_hh_l0.data = model2.encoder_GRU[i].weight_hh_l0.data
            model.encoder_GRU[i].weight_ih_l0.data = model2.encoder_GRU[i].weight_ih_l0.data
            model.encoder_GRU[i].weight_hh_l0_reverse.data = model2.encoder_GRU[i].weight_hh_l0_reverse.data
            model.encoder_GRU[i].weight_ih_l0_reverse.data = model2.encoder_GRU[i].weight_ih_l0_reverse.data
            model.encoder_linear[i].weight.data = model2.encoder_linear[i].weight.data
        model.affine_c.weight.data = model2.affine_c.weight.data
        model.embedding.weight.data[:len(model2.embedding.weight.data), :] = model2.embedding.weight.data

##### For Transfer Learning ###
            
    model.train()
    
    if args['--cuda'] != '-1':        
        device = torch.device("cuda:" + str(args['--cuda']))
    else:
        device = torch.device("cpu")
    print('use device: %s' % device, file=sys.stderr)
    print('use device: %s' % device, file=log_file)
    
    '''
    if continue_training:
        optimizer_state_dict = torch.load(args['--model-path'] + '.optim')
        optimizer = torch.optim.Adam(model.parameters())
        optimizer.load_state_dict(optimizer_state_dict)
    else:
        optimizer = torch.optim.Adam(model.parameters(), lr=float(args['--lr']))
    '''
    optimizer = torch.optim.Adam(model.parameters(), lr=float(args['--lr']))    
    model = model.to(device)
    
    CELoss = nn.CrossEntropyLoss(reduction = 'sum').to(device)

    num_trial = 0
    train_iter = patience = cum_loss = report_loss = 0
    cum_examples = report_examples = epoch = valid_num = 0
    hist_valid_scores = []
    train_time = begin_time = time.time()
    print('begin Maximum Likelihood training', file = sys.stderr)
    print('begin Maximum Likelihood training', file = log_file)
    
    log_file.close()
    
    while True:
        epoch += 1
        
        for src_sents, labels in batch_iter(train_data, batch_size=train_batch_size, shuffle=True):
            train_iter += 1
            
            optimizer.zero_grad()
            batch_size = len(src_sents)
            
            labels = torch.tensor(labels, device = device)
            
            P = model(src_sents)
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
                accuracy = validation(model, dev_data, batch_size=64)   # dev batch size can be a bit larger
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

                    if patience == int(args['--patience']):
                        num_trial += 1
                        print('hit #%d trial' % num_trial, file=sys.stderr)
                        print('hit #%d trial' % num_trial, file=log_file)
                        if num_trial == int(args['--max-num-trial']):
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
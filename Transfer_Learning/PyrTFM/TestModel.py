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

vocab = Vocab('vocab_total.txt')
model = TFMClassifier.load('3_layer_TFL.bin', vocab = vocab)
batch_size = 32
input_length = 304
device = 'cpu'

cum_examples = 0
cum_correct = 0

dev_data_src, dev_data_label = read_corpus('src_val.txt')
test_data_src, test_data_label = read_corpus('src_test.txt')
dev_data = list(zip(dev_data_src, dev_data_label))
test_data = list(zip(test_data_src, test_data_label))
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
dev_correct = cum_correct
dev_examples = cum_examples
                
with torch.no_grad():
    for src_sents, labels in batch_iter(test_data, batch_size):
        src = vocab.to_input_tensor(src_sents, input_length, device = device)
        dec_init = torch.tensor([[vocab['<sos>']] for i in range(len(labels))])
        src_mask = create_src_mask(src, vocab['<pad>'], device = device)
        cum_examples += len(labels)
        
        P = model(src, dec_init, src_mask)
        label_pres = torch.argmax(P, dim = -1)
        for i in range(len(label_pres)):
            if label_pres[i] == labels[i]:
                cum_correct += 1
                
test_correct = cum_correct - dev_correct
test_examples = cum_examples - dev_examples
                
print('correct rate: %.3f'%(cum_correct/cum_examples))
print('validation CR: %.3f'%(dev_correct/dev_examples))
print('test CR: %.3f'%(test_correct/test_examples))
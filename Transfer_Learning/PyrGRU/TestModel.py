import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
from typing import List, Tuple, Dict, Set, Union
from collections import namedtuple
from Vocab_word import Vocab
from utils import read_corpus, batch_iter

from Classification import Classification

vocab = Vocab('vocab_total.txt')
model = Classification.load('word_enc_dec_lastlayer_new.bin', vocab = vocab)
batch_size = 32

cum_examples = 0
cum_correct = 0

dev_data_src, dev_data_label = read_corpus('src_val.txt')
test_data_src, test_data_label = read_corpus('src_test.txt')
dev_data = list(zip(dev_data_src, dev_data_label))
test_data = list(zip(test_data_src, test_data_label))
with torch.no_grad():
    for src_sents, labels in batch_iter(dev_data, batch_size):
        cum_examples += len(src_sents)
        P = model(src_sents)
        label_pres = torch.argmax(P, dim = -1)
        for i in range(len(label_pres)):
            if label_pres[i] == labels[i]:
                cum_correct += 1
dev_correct = cum_correct
dev_examples = cum_examples
                
with torch.no_grad():
    for src_sents, labels in batch_iter(test_data, batch_size):
        cum_examples += len(src_sents)
        P = model(src_sents)
        label_pres = torch.argmax(P, dim = -1)
        for i in range(len(label_pres)):
            if label_pres[i] == labels[i]:
                cum_correct += 1
                
test_correct = cum_correct - dev_correct
test_examples = cum_examples - dev_examples
                
print('correct rate: %.3f'%(cum_correct/cum_examples))
print('validation CR: %.3f'%(dev_correct/dev_examples))
print('test CR: %.3f'%(test_correct/test_examples))
import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
from typing import List, Tuple, Dict, Set, Union
from collections import namedtuple
from Vocab_word import Vocab

from Classification import Classification
from NLC import NLC

uniform_init = 0.1
vocab = Vocab('vocab_total.txt')
vocab_old = Vocab('vocab_old.txt')
enc_layers = 3
model = Classification(input_length = 304, num_class = 44, embed_size = 400, enc_hidden_size = 400, attention_size = 400, ff_size = 2048, vocab = vocab)
model2 = NLC.load('model400.bin', vocab_old)
print(model)
print(model2)
for p in model.parameters():
    p.data.uniform_(-uniform_init, uniform_init)
model.embedding.weight.data = model2.embedding.weight.data
for i in range(enc_layers - 1):
    model.encoder_GRU[i].weight_hh_l0.data = model2.encoder_GRU[i].weight_hh_l0.data
    model.encoder_GRU[i].weight_ih_l0.data = model2.encoder_GRU[i].weight_ih_l0.data
    model.encoder_GRU[i].weight_hh_l0_reverse.data = model2.encoder_GRU[i].weight_hh_l0_reverse.data
    model.encoder_GRU[i].weight_ih_l0_reverse.data = model2.encoder_GRU[i].weight_ih_l0_reverse.data
    model.encoder_linear[i].weight.data = model2.encoder_linear[i].weight.data
model.affine_c.weight.data = model2.affine_c.weight.data
model.embedding.weight.data[:len(model2.embedding.weight.data), :] = model2.embedding.weight.data

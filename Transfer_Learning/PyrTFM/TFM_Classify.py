import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
import math
import copy
from torch.autograd import Variable
from modules import Embedder, PositionalEncoder, MultiHeadAttention, FeedForward, Norm, FeedForward_enc
from utils import create_src_mask, create_tgt_mask
from collections import namedtuple
from Vocab_word import Vocab
from utils_model import Reinit, ExpandVocab

def get_clones(module, N):
    return nn.ModuleList([copy.deepcopy(module) for i in range(N)])
    
class EncoderLayer(nn.Module):
    def __init__(self, d_model, heads, dropout = 0.1):
        super().__init__()
        self.norm_1 = Norm(d_model)
        self.norm_2 = Norm(d_model)
        self.attn = MultiHeadAttention(heads, d_model, dropout)
        self.ff = FeedForward_enc(d_model)
        self.dropout_1 = nn.Dropout(dropout)
        self.dropout_2 = nn.Dropout(dropout)
        
    def forward(self, x, mask, device):
        x2 = self.norm_1(x)
        x = x + self.dropout_1(self.attn(x2,x2,x2,mask))
        x2 = self.norm_2(x)
        x2 = self.dropout_2(self.ff(x2, device = device))
        idx_odd = torch.tensor([2*i+1 for i in range(x.shape[1]//2)]).to(device)
        idx_even = idx_odd - 1
        x = (torch.index_select(x, 1, idx_odd).to(device) + torch.index_select(x, 1, idx_even).to(device))/2.0
        x = x + x2
        return x
        
class Encoder(nn.Module):
    def __init__(self, max_seq_len, vocab_size, d_model, N, heads, dropout = 0.1):
        super().__init__()
        self.N = N
        self.embed = Embedder(vocab_size, d_model)
        self.pe = PositionalEncoder(d_model, max_seq_len)
        self.layers = get_clones(EncoderLayer(d_model, heads, dropout), N)
        self.norm = Norm(d_model)
    def forward(self, src, mask, device):
        x = self.embed(src)
        x = self.pe(x)
        for i in range(self.N):
            x = self.layers[i](x, mask, device = device)
            idx_odd = torch.tensor([2*i+1 for i in range(mask.shape[2]//2)]).to(device)
            idx_even = idx_odd - 1
            mask_odd = torch.index_select(mask, 2, idx_odd).to(device)
            mask_even = torch.index_select(mask, 2, idx_even).to(device)
            mask = mask_odd | mask_even
        return self.norm(x), mask
        
class DecoderLayer(nn.Module):
    def __init__(self, d_model, heads, dropout=0.1):
        super().__init__()
        self.norm_1 = Norm(d_model)
        self.norm_2 = Norm(d_model)
        
        self.dropout_1 = nn.Dropout(dropout)
        self.dropout_2 = nn.Dropout(dropout)
        
        self.attn_1 = MultiHeadAttention(heads, d_model, dropout)
        self.ff = FeedForward(d_model)
        
    def forward(self, x, e_outputs, src_mask):
        x2 = self.norm_1(x)
        x = x + self.dropout_1(self.attn_1(x2, e_outputs, e_outputs, src_mask))
        x2 = self.norm_2(x)
        x = x + self.dropout_2(self.ff(x2))
        return x
        
class Decoder(nn.Module):
    def __init__(self, vocab_size, d_model, N, heads, dropout = 0.1):
        super().__init__()
        self.N = N
        self.embed = Embedder(vocab_size, d_model)
        #self.pe = PositionalEncoder(d_model, max_seq_len)
        self.layers = get_clones(DecoderLayer(d_model, heads, dropout), N)
        self.norm = Norm(d_model)
    def forward(self, tgt, e_outputs, src_mask):
        x = self.embed(tgt)
        for i in range(self.N):
            x = self.layers[i](x, e_outputs, src_mask)
        return self.norm(x)
        
class TFMClassifier(nn.Module):
    def __init__(self, max_enc_len, vocab, d_model, enc_layers, dec_layers, heads, num_classes, dropout, device = 'cpu'):
        super().__init__()
        self.V_size = len(vocab)
        self.num_classes = num_classes
        self.max_enc_len = max_enc_len
        self.d_model = d_model
        self.enc_layers = enc_layers
        self.dec_layers = dec_layers
        self.heads = heads
        self.dropout = dropout
        self.encoder = Encoder(self.max_enc_len, self.V_size, self.d_model, self.enc_layers, self.heads, self.dropout)
        self.decoder = Decoder(self.V_size, self.d_model, self.dec_layers, self.heads, self.dropout)
        self.out = nn.Linear(self.d_model, self.num_classes)
        self.vocab = vocab
        self.device = device
        
    def forward(self, src, tgt, src_mask):
        #src = self.vocab.to_input_tensor(src)
        e_outputs, src_mask = self.encoder(src, src_mask, device = self.device)
        d_output = self.decoder(tgt, e_outputs, src_mask)
        output = self.out(d_output)
        return output    
        
    @staticmethod
    def load(model_path: str, vocab):
        params = torch.load(model_path, map_location=lambda storage, loc: storage)
        args = params['args']
        model = TFMClassifier(vocab=vocab, **args)
        model.load_state_dict(params['state_dict'])

        return model

    def save(self, path: str):
        print('save model parameters to [%s]' % path, file=sys.stderr)

        params = {
            'args': dict(max_enc_len=self.max_enc_len,
                         d_model=self.d_model,
                         enc_layers=self.enc_layers,
                         dec_layers=self.dec_layers,
                         heads=self.heads,
                         num_classes = self.num_classes,
                         dropout=self.dropout),
            'vocab': self.vocab,
            'state_dict': self.state_dict()
        }

        torch.save(params, path)

'''
from model_TFM import Transformer
from utils import read_corpus, batch_iter

vocab_old = Vocab('vocab_old.txt')
model1 = Transformer.load('original.bin', vocab = vocab_old)
vocab = Vocab('vocab_total.txt')        
model = TFMClassifier(vocab = vocab, max_enc_len = 304, d_model = 512, enc_layers = 3, dec_layers = 1, heads = 8, num_classes = 44, dropout = 0.1)

model1 = Reinit(model1)
model1 = ExpandVocab(model1, vocab_old, vocab)

model.encoder = model1.encoder
print(model.encoder.embed.embed.weight.data.shape)

train_data_src, train_data_label = read_corpus('src_train.txt')
dev_data_src, dev_data_label = read_corpus('src_val.txt')
train_data = list(zip(train_data_src, train_data_label))

for src_sents, labels in batch_iter(train_data, batch_size=16, shuffle=True):
    src = vocab.to_input_tensor(src_sents, 304, device = 'cpu')
    tgt = torch.tensor([[vocab['<sos>']] for i in range(16)])
    src_mask = create_src_mask(src, vocab['<pad>'], device = 'cpu')
    print(model(src, tgt, src_mask).shape)
    
    exit()

'''
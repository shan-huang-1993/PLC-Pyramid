import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
from typing import List, Tuple, Dict, Set, Union
from collections import namedtuple
from Vocab_word import Vocab
from utils import read_corpus, pad_idx_tensor

Hypothesis = namedtuple('Hypothesis', ['value', 'score'])

class Classification(nn.Module):
    def __init__(self, input_length, num_class, embed_size, enc_hidden_size, attention_size, ff_size, vocab, enc_layers = 3, dropout_rate = 0.15):
        super(Classification, self).__init__()
        self.input_length = input_length
        self.embed_size = embed_size
        self.enc_hidden_size = enc_hidden_size
        self.ff_size = ff_size
        self.attention_size = attention_size
        self.enc_layers = enc_layers
        self.vocab = vocab
        self.num_class = num_class
        self.dropout_rate = dropout_rate
        
        self.embedding = nn.Embedding(num_embeddings = len(self.vocab), embedding_dim = self.embed_size, padding_idx = self.vocab.pad_token)
        self.encoder_GRU = []
        self.encoder_linear = []
        for i in range(self.enc_layers):
            self.encoder_GRU.append(nn.GRU(input_size = self.embed_size, hidden_size = self.enc_hidden_size, bidirectional = True))
            self.encoder_linear.append(nn.Linear(in_features = self.enc_hidden_size * 2, out_features = self.embed_size, bias = True))
        self.encoder_GRU = nn.ModuleList(self.encoder_GRU)
        self.encoder_linear = nn.ModuleList(self.encoder_linear)
        
        self.ff1 = nn.Linear(in_features = self.enc_hidden_size + self.embed_size, out_features = self.ff_size, bias = True)
        self.ff2 = nn.Linear(in_features = self.ff_size, out_features = self.num_class, bias = True)
        
        self.affine_c = nn.Linear(in_features = self.embed_size, out_features = self.attention_size, bias = True)
        self.affine_d = nn.Linear(in_features = self.enc_hidden_size, out_features = self.attention_size, bias = True)
        self.dropout = nn.Dropout(p = self.dropout_rate)
        
    def forward(self, source):
        source_lengths = [float(len(s)) for s in source]
        source_padded = torch.transpose(self.vocab.to_input_tensor(source, self.input_length, self.device),0,1)
        X_emb = self.embedding(source_padded)
        del(source_padded)
        
        c, dec_init_state = self.encode(X_emb)
        del(X_emb)
        
        o = self.attention(c, dec_init_state)
        o = self.dropout(o)
        o = self.ff2(F.relu(self.ff1(o))) #(1, batch, num_class)
        
        del(c)
        del(dec_init_state)
        
        P = F.softmax(o, dim=-1)
        P = torch.squeeze(P, dim=0)
        
        return P
        
    def encode(self, inputs):
        #use zero initial hidden state for encoder
        c_t = inputs
        for j in range(self.enc_layers):
            outputs, h_Tj= self.encoder_GRU[j](c_t)
            f_t = outputs[:, :, :self.enc_hidden_size]
            b_t = outputs[:, :, self.enc_hidden_size:]
            h_t = f_t + b_t
            idx_odd = torch.tensor([2*i+1 for i in range(h_t.shape[0]//2)], device=self.device)
            idx_even = idx_odd - 1
            c_t = torch.cat((torch.index_select(h_t, 0, idx_odd), torch.index_select(h_t, 0, idx_even)),2)
            c_t = torch.tanh(self.encoder_linear[j](c_t))
        dec_init_state = h_Tj[1:, :, :]
        return c_t, dec_init_state
        
    def attention(self, c, d_t):
        # Here c is of shape([batch, seq_length, hid_size])
        psi_c = torch.transpose(torch.transpose(F.relu(self.affine_c(c)), 0, 1), 1, 2)
        psi_d = torch.transpose(F.relu(self.affine_d(d_t)), 0, 1)
        u_t = torch.bmm(psi_d, psi_c) # U is of shape [batch, 1, seq_length]
        alpha_t = torch.mul(u_t, 1/(torch.sum(u_t, 2, keepdim = True)+0.000001))
        a_t = torch.bmm(alpha_t, torch.transpose(c, 0, 1)) # This may be problematic, which axis???
        a_t = torch.transpose(a_t, 0, 1) #a_t is of shape([batch, 1, emb_size])
        o_t = torch.cat((d_t, a_t), 2)
        return o_t
        
    @property
    def device(self) -> torch.device:
        """ Determine which device to place the Tensors upon, CPU or GPU.
        """
        return self.embedding.weight.device
        
    @staticmethod
    def load(model_path: str, vocab):
        """ Load the model from a file.
        @param model_path (str): path to model
        """
        params = torch.load(model_path, map_location=lambda storage, loc: storage)
        args = params['args']
        model = Classification(vocab=vocab, **args)
        model.load_state_dict(params['state_dict'])

        return model

    def save(self, path: str):
        """ Save the model to a file.
        @param path (str): path to the model
        """
        print('save model parameters to [%s]' % path, file=sys.stderr)

        params = {
            'args': dict(input_length=self.input_length,
                         num_class = self.num_class,
                         embed_size=self.embed_size,
                         enc_hidden_size=self.enc_hidden_size,
                         enc_layers = self.enc_layers,
                         attention_size=self.attention_size,
                         dropout_rate=self.dropout_rate,
                         ff_size = self.ff_size),
                         
            'vocab': self.vocab,
            'state_dict': self.state_dict()
        }

        torch.save(params, path)

def test_train():
    vocab = Vocab('vocab_total.txt')
    source, label = read_corpus('src_test.txt')
    source = source[:32]
    label = label[:32]
    model = Classification(input_length = 304, num_class = 44, embed_size = 400, enc_hidden_size = 400, attention_size = 400, ff_size = 2048, vocab = vocab)
    print(model(source).shape)

#test_train()
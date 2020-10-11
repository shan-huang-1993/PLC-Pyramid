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

Hypothesis = namedtuple('Hypothesis', ['value', 'score'])

# We can build a convenient cloning function that can generate multiple layers:
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
    
# build a decoder layer with two multi-head attention layers and
# one feed-forward layer
class DecoderLayer(nn.Module):
    def __init__(self, d_model, heads, dropout=0.1):
        super().__init__()
        self.norm_1 = Norm(d_model)
        self.norm_2 = Norm(d_model)
        self.norm_3 = Norm(d_model)
        
        self.dropout_1 = nn.Dropout(dropout)
        self.dropout_2 = nn.Dropout(dropout)
        self.dropout_3 = nn.Dropout(dropout)
        
        self.attn_1 = MultiHeadAttention(heads, d_model, dropout)
        self.attn_2 = MultiHeadAttention(heads, d_model, dropout)
        self.ff = FeedForward(d_model)
        
    def forward(self, x, e_outputs, src_mask, tgt_mask):
        x2 = self.norm_1(x) # x(batch, seq_length, d_model)
        x = x + self.dropout_1(self.attn_1(x2, x2, x2, tgt_mask))
        x2 = self.norm_2(x)
        x = x + self.dropout_2(self.attn_2(x2, e_outputs, e_outputs, src_mask))
        x2 = self.norm_3(x)
        x = x + self.dropout_3(self.ff(x2))
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
    
class Decoder(nn.Module):
    def __init__(self, max_seq_len, vocab_size, d_model, N, heads, dropout = 0.1):
        super().__init__()
        self.N = N
        self.embed = Embedder(vocab_size, d_model)
        self.pe = PositionalEncoder(d_model, max_seq_len)
        self.layers = get_clones(DecoderLayer(d_model, heads, dropout), N)
        self.norm = Norm(d_model)
    def forward(self, tgt, e_outputs, src_mask, tgt_mask):
        x = self.embed(tgt)
        x = self.pe(x)
        for i in range(self.N):
            x = self.layers[i](x, e_outputs, src_mask, tgt_mask)
        return self.norm(x)
            
class Transformer(nn.Module):
    def __init__(self, max_enc_len, max_dec_len, vocab, d_model, enc_layers, dec_layers, heads, dropout, device = 'cpu'):
        super().__init__()
        self.V_size = len(vocab)
        self.max_enc_len = max_enc_len
        self.max_dec_len = max_dec_len
        self.d_model = d_model
        self.enc_layers = enc_layers
        self.dec_layers = dec_layers
        self.heads = heads
        self.dropout = dropout
        self.encoder = Encoder(self.max_enc_len, self.V_size, self.d_model, self.enc_layers, self.heads, self.dropout)
        self.decoder = Decoder(self.max_dec_len, self.V_size, self.d_model, self.dec_layers, self.heads, self.dropout)
        self.out = nn.Linear(self.d_model, self.V_size)
        self.vocab = vocab
        self.device = device
        
    def forward(self, src, tgt, src_mask, tgt_mask):
        #src = self.vocab.to_input_tensor(src)
        e_outputs, src_mask = self.encoder(src, src_mask, device = self.device)
        d_output = self.decoder(tgt, e_outputs, src_mask, tgt_mask)
        output = self.out(d_output)
        return output
    
    def beam_search(self, src, src_mask, beam_size = 5, max_len = 500):
        e_output = self.encoder(src, src_mask)
        
        hypotheses = [[self.vocab['<sos>']]]
        hyp_scores = torch.zeros(len(hypotheses), dtype=torch.float)
        completed_hypotheses = []
        
        t = 0
        while len(completed_hypotheses) < beam_size and t < max_len:
            t += 1
            hyp_num = len(hypotheses)
            live_hyp_num = beam_size - len(completed_hypotheses)
            input_hyps = torch.tensor([hyp[:t] for hyp in hypotheses])
            e_outputs = torch.cat([e_output] * hyp_num)
            
            nopeak_mask = np.triu(np.ones((1, t, t)), k = 1).astype('uint8')
            nopeak_mask = Variable(torch.from_numpy(nopeak_mask) == 0)
            
            o_t = self.out(self.decoder(input_hyps, e_outputs, src_mask, nopeak_mask))
            log_p_t = F.log_softmax(o_t[:, -1, :], dim=-1) #make log_p_t (beam_size, V_size)
            contiuating_hyp_scores = (hyp_scores.unsqueeze(1).expand_as(log_p_t) + log_p_t).view(-1)
            top_cand_hyp_scores, top_cand_hyp_pos = torch.topk(contiuating_hyp_scores, k=live_hyp_num)

            prev_hyp_ids = top_cand_hyp_pos / len(self.vocab)
            hyp_word_ids = top_cand_hyp_pos % len(self.vocab)
            
            new_hypotheses = []
            live_hyp_ids = []
            new_hyp_scores = []
            
            for prev_hyp_id, hyp_word_id, cand_new_hyp_score in zip(prev_hyp_ids, hyp_word_ids, top_cand_hyp_scores):
                prev_hyp_id = prev_hyp_id.item()
                hyp_word_id = hyp_word_id.item()
                cand_new_hyp_score = cand_new_hyp_score.item()
                
                new_hyp_sent = hypotheses[prev_hyp_id] + [hyp_word_id]
                
                if hyp_word_id == self.vocab['<eos>']:
                    s = []
                    for idx in new_hyp_sent[1:-1]:
                        s.append(self.vocab.id2word(idx))
                    s = ''.join(s)
                    completed_hypotheses.append(Hypothesis(value=s, score=cand_new_hyp_score))
                else:
                    new_hypotheses.append(new_hyp_sent)
                    live_hyp_ids.append(prev_hyp_id)
                    new_hyp_scores.append(cand_new_hyp_score)

                if len(completed_hypotheses) == beam_size:
                    break
                    
            live_hyp_ids = torch.tensor(live_hyp_ids, dtype=torch.long)
            hypotheses = new_hypotheses
            hyp_scores = torch.tensor(new_hyp_scores, dtype=torch.float)
            
            if len(completed_hypotheses) == 0:
                s = []
                for idx in hypotheses[0][1:]:
                    s.append(self.vocab.id2word(idx))
                s = ''.join(s)
                completed_hypotheses.append(Hypothesis(value=s,
                                                       score=hyp_scores[0].item()/max_len))

            completed_hypotheses.sort(key=lambda hyp: hyp.score, reverse=True)

            return completed_hypotheses
        
    @staticmethod
    def load(model_path: str, vocab):
        params = torch.load(model_path, map_location=lambda storage, loc: storage)
        args = params['args']
        model = Transformer(vocab=vocab, **args)
        model.load_state_dict(params['state_dict'])

        return model

    def save(self, path: str):
        print('save model parameters to [%s]' % path, file=sys.stderr)

        params = {
            'args': dict(max_enc_len=self.max_enc_len,
                         max_dec_len=self.max_dec_len,
                         d_model=self.d_model,
                         enc_layers=self.enc_layers,
                         dec_layers=self.dec_layers,
                         heads=self.heads,
                         dropout=self.dropout),
            'vocab': self.vocab,
            'state_dict': self.state_dict()
        }

        torch.save(params, path)
    
def test():
    vocab = Vocab('vocab.txt')
    model = Transformer(vocab = vocab, max_enc_len = 304, max_dec_len = 304, d_model = 512, enc_layers = 3, dec_layers = 3, heads = 8, dropout = 0.1)
    src_batch = torch.empty(16,304).random_(10).long()
    tgt_batch = torch.empty(16,304).random_(10).long()
    pad = 0
    src_msk = create_src_mask(src_batch, pad, 'cpu')
    tgt_msk = create_tgt_mask(tgt_batch, pad, 'cpu')
    out = model(src_batch, tgt_batch, src_msk, tgt_msk)
    print('out: ', out.shape)
    
def test_generate():
    vocab = Vocab('vocab.txt')
    model = Transformer(vocab = vocab, d_model = 20, N = 1, heads = 4)
    src = torch.empty(1,40).random_(10).long()
    src_mask = create_src_mask(src, 0)
    model.beam_search(src, src_mask, beam_size = 5, max_len = 40)
    
    
#test()
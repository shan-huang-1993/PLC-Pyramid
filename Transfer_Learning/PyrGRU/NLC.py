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

class NLC(nn.Module):
    def __init__(self, input_length, embed_size, enc_hidden_size, dec_hidden_size, attention_size, vocab, enc_layers = 3, dec_layers = 3, dropout_rate = 0.15):
        super(NLC, self).__init__()
        self.input_length = input_length
        self.embed_size = embed_size
        self.enc_hidden_size = enc_hidden_size
        self.dec_hidden_size = dec_hidden_size
        self.attention_size = attention_size
        self.enc_layers = enc_layers
        self.dec_layers = dec_layers
        self.vocab = vocab
        #V_size will be changed back once vocab.py is finished
        self.V_size = len(vocab)
        self.dropout_rate = dropout_rate
        
        self.embedding = nn.Embedding(num_embeddings = len(self.vocab), embedding_dim = self.embed_size, padding_idx = self.vocab.pad_token)
        self.encoder_GRU = []
        self.encoder_linear = []
        for i in range(self.enc_layers):
            self.encoder_GRU.append(nn.GRU(input_size = self.embed_size, hidden_size = self.enc_hidden_size, bidirectional = True))
            self.encoder_linear.append(nn.Linear(in_features = self.enc_hidden_size * 2, out_features = self.embed_size, bias = True))
        self.encoder_GRU = nn.ModuleList(self.encoder_GRU)
        self.encoder_linear = nn.ModuleList(self.encoder_linear)
        
        self.decoder_GRU = nn.GRU(input_size = self.embed_size, hidden_size = self.dec_hidden_size, num_layers = self.dec_layers)
        self.affine_c = nn.Linear(in_features = self.embed_size, out_features = self.attention_size, bias = True)
        self.affine_d = nn.Linear(in_features = self.dec_hidden_size, out_features = self.attention_size, bias = True)
        self.output_proj = nn.Linear(in_features = self.dec_hidden_size + self.embed_size, out_features = self.V_size, bias = True)
        self.dropout = nn.Dropout(p = self.dropout_rate)
        
    def forward(self, source, target):
        #source, target are list of strings
        source_lengths = [float(len(s)) for s in source]
        #source/target_padded are list of integers
        source_padded = torch.transpose(self.vocab.to_input_tensor(source, self.input_length, self.device),0,1)
        target_padded = torch.transpose(self.vocab.to_input_tensor(target, self.input_length, self.device),0,1)

        X_emb = self.embedding(source_padded)
        Y_emb = self.embedding(target_padded)
        
        del(source_padded)
        
        c, dec_init_state = self.encode(X_emb)
        
        del(X_emb)
        
        o = self.output_proj(self.decode(c, Y_emb, dec_init_state))
        
        del(c)
        del(dec_init_state)
        del(Y_emb)
        
        P = F.log_softmax(o, dim=-1)
        
        target_masks = (target_padded != self.vocab['<pad>']).float()
        target_gold_words_log_prob = torch.gather(P, index=target_padded[1:].unsqueeze(-1), dim=-1).squeeze(-1) * target_masks[1:]
        
        del(target_masks)
        del(target_padded)
         
        CELoss = -target_gold_words_log_prob.sum(dim=0)
        return CELoss
        
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
    
    def decode(self, c, Y, dec_init_state):
        #For decoder, its initial state will be the last output of encoder for all layers.
        #Y.shape == [tgt_len, batch, emb_size], Y here is after embedding
        Y = Y[:-1]
        o = []
        dec_state = torch.cat([dec_init_state]*self.dec_layers)
        for Y_t in torch.split(Y, [1] * Y.shape[0]):
            o_t, dec_state = self.step(Y_t, dec_state, c)
            o.append(o_t)
        o = torch.cat(o, 0).to(self.device)
        
        return o
        
    def step(self, inputs, dec_states_input, c):
        d_t, dec_states_output = self.decoder_GRU(inputs, dec_states_input)
        o_t = self.attention(c, d_t) #o_t.shape==[batch, 1, dec_hid_size + emb_size]
        o_t = self.dropout(o_t)
        return o_t, dec_states_output
        
        
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
        
    def beam_search(self, source, beam_size = 5, max_decoding_time_step = 400):
        """ Given a single source sentence, perform beam search, yielding translations in the target language.
        @param src_sent (List[str]): a single source sentence (words)
        @param beam_size (int): beam size
        @param max_decoding_time_step (int): maximum number of time steps to unroll the decoding RNN
        @returns hypotheses (List[Hypothesis]): a list of hypothesis, each hypothesis has two fields:
                value: List[str]: the decoded target sentence, represented as a list of words
                score: float: the log-likelihood of the target sentence
        """
        source_padded = torch.transpose(self.vocab.to_input_tensor(source, self.input_length, self.device),0,1)
        X_emb = self.embedding(source_padded)
        #src_sents_var = self.vocab.src.to_input_tensor([src_sent], self.device)

        c, dec_init_state = self.encode(X_emb) #c->[1, 1, embed_size], dec_init_state->[1, 1, hid_size]
        #src_encodings, dec_init_vec = self.encode(src_sents_var, [len(src_sent)])
        #src_encodings_att_linear = self.att_projection(src_encodings)

        h_tm1 = torch.cat([dec_init_state]*self.dec_layers).to(self.device) #h_tm1->[dec_layers, 1, hid_size]
        #att_tm1 = torch.zeros(1, self.hidden_size, device=self.device)

        #eos_id = self.vocab.tgt['</s>']
        
        hypotheses = [[self.vocab.start_token]]
        hyp_scores = torch.zeros(len(hypotheses), dtype=torch.float, device=self.device)
        #hypotheses = [['<s>']]
        #hyp_scores = torch.zeros(len(hypotheses), dtype=torch.float, device=self.device)
        completed_hypotheses = []

        t = 0
        while len(completed_hypotheses) < beam_size and t < max_decoding_time_step:
            t += 1
            hyp_num = len(hypotheses)
            exp_c = c.expand(c.size(0), hyp_num, c.size(2))
            #print('exp_c', exp_c.shape)
            #exp_src_encodings = src_encodings.expand(hyp_num,
            #                                         src_encodings.size(1),
            #                                         src_encodings.size(2))
            
            #exp_src_encodings_att_linear = src_encodings_att_linear.expand(hyp_num,
            #                                                               src_encodings_att_linear.size(1),
            #                                                               src_encodings_att_linear.size(2))
            
            y_tm1 = torch.tensor([[hyp[-1] for hyp in hypotheses]], dtype = torch.long, device=self.device) #y_tm1 -> [hyp_num, emb_size]
            #print('y_tm1 ', y_tm1.shape)
            #print('h_tm1 ', h_tm1.shape)
            #y_tm1 = torch.tensor([self.vocab.tgt[hyp[-1]] for hyp in hypotheses], dtype=torch.long, device=self.device)
            y_t_embed = self.embedding(y_tm1) #y_t_emb -> [1, hyp_num, emb_size]
            #print('y_t_embed ', y_t_embed.shape)
            #y_t_embed = self.model_embeddings.target(y_tm1)

            #x = torch.cat([y_t_embed, att_tm1], dim=-1)
            
            o_t, h_t = self.step(y_t_embed, h_tm1, exp_c) #o_t -> [1, hyp_num, out_size], h_t -> [num_layers, hyp_num, dec_hid_size]
            #print('o_t ', o_t.shape)
            #print('h_t ', h_t.shape)
            #(h_t, cell_t), att_t, _  = self.step(x, h_tm1,
            #                                          exp_src_encodings, exp_src_encodings_att_linear, enc_masks=None)

            # log probabilities over target words
            log_p_t = F.log_softmax(self.output_proj(o_t), dim=-1) #log_p_t->[1, hyp_num, V_size]
            
            live_hyp_num = beam_size - len(completed_hypotheses)
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

                #hyp_word = self.vocab.tgt.id2word[hyp_word_id]
                new_hyp_sent = hypotheses[prev_hyp_id] + [hyp_word_id]
                if hyp_word_id == self.vocab.end_token:
                    s = []
                    for idx in new_hyp_sent[1:-1]:
                        s.append(self.vocab.id2char(idx))
                    s = ''.join(s)
                    completed_hypotheses.append(Hypothesis(value=s,
                                                           score=cand_new_hyp_score))
                else:
                    new_hypotheses.append(new_hyp_sent)
                    live_hyp_ids.append(prev_hyp_id)
                    new_hyp_scores.append(cand_new_hyp_score)

            if len(completed_hypotheses) == beam_size:
                break

            live_hyp_ids = torch.tensor(live_hyp_ids, dtype=torch.long, device=self.device)
            #print('live_hyp_ids ', live_hyp_ids)
            h_tm1 = h_t[:, live_hyp_ids, :]
            #h_tm1 = (h_t[live_hyp_ids], cell_t[live_hyp_ids])
            #att_tm1 = att_t[live_hyp_ids]

            hypotheses = new_hypotheses

            #print('hypotheses', hypotheses)
            hyp_scores = torch.tensor(new_hyp_scores, dtype=torch.float, device=self.device)
            #print(hyp_scores)
        
        if len(completed_hypotheses) == 0:
            s = []
            for idx in hypotheses[0][1:]:
                s.append(self.vocab.id2char(idx))
            s = ' '.join(s)
            completed_hypotheses.append(Hypothesis(value=s,
                                                   score=hyp_scores[0].item()/max_decoding_time_step))

        completed_hypotheses.sort(key=lambda hyp: hyp.score, reverse=True)

        return completed_hypotheses
        
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
        model = NLC(vocab=vocab, **args)
        model.load_state_dict(params['state_dict'])

        return model

    def save(self, path: str):
        """ Save the model to a file.
        @param path (str): path to the model
        """
        print('save model parameters to [%s]' % path, file=sys.stderr)

        params = {
            'args': dict(input_length=self.input_length,
                         embed_size=self.embed_size,
                         enc_hidden_size=self.enc_hidden_size,
                         dec_hidden_size=self.dec_hidden_size,
                         attention_size=self.attention_size,
                         dropout_rate=self.dropout_rate),
            'vocab': self.vocab,
            'state_dict': self.state_dict()
        }

        torch.save(params, path)

def test_train():
    vocab = Vocab_char(embed_size = 3)
    source = read_corpus('NLC/src_test.txt', 400)[:4]
    target = read_corpus('NLC/dst_test.txt', 400)[:4]
    model = NLC(input_length = 400, embed_size = vocab.embed_size, enc_hidden_size = 4, dec_hidden_size = 4, attention_size = 5, vocab = vocab)
    model(source, target)
    
def test_generate():
    vocab = Vocab_char()
    model = NLC.load('model400.bin', vocab = vocab)
    input_sents = read_corpus('NLC/src_test.txt', 400)
    target_sents = read_corpus('NLC/dst_test.txt', 400)
    count = [0] * 4
    for i in range(len(input_sents)):
        input_sent = input_sents[i:(i+1)]
        target_sent = target_sents[i:(i+1)]
        completed_hypotheses = model.beam_search(input_sent)
        hyp_sents = [hyp.value for hyp in completed_hypotheses]
        if input_sent[0] == target_sent[0]:
            count[0] += 1
            if target_sent[0] in hyp_sents:
                count[1] += 1
        if input_sent[0] in hyp_sents:
            count[2] += 1
        if target_sent[0] in hyp_sents:
            count[3] += 1
        print('[%d/%d]'%(i, len(input_sents)), end = '\r')
    print(count)

#test_generate()
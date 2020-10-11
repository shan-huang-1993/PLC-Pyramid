import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
from typing import List, Tuple, Dict, Set, Union
from collections import namedtuple
from PLC_Model.Vocab_word import Vocab
from PLC_Model.utils import read_corpus, pad_idx_tensor

Hypothesis = namedtuple('Hypothesis', ['value', 'score'])

class GRU(nn.Module):
    def __init__(self, input_length, embed_size, enc_hidden_size, dec_hidden_size, attention_size, vocab, enc_layers = 3, dec_layers = 3, dropout_rate = 0.15, pyramid=False, attention_type='Bahdanau'):
        super(GRU, self).__init__()
        self.input_length = input_length
        self.embed_size = embed_size
        self.enc_hidden_size = enc_hidden_size
        self.dec_hidden_size = dec_hidden_size
        self.attention_size = attention_size
        self.enc_layers = enc_layers
        self.dec_layers = dec_layers
        self.vocab = vocab
        self.V_size = len(vocab)
        self.dropout_rate = dropout_rate
        self.pyramid = pyramid
        self.attention_type = attention_type
        
        self.embedding = nn.Embedding(num_embeddings = len(self.vocab), embedding_dim = self.embed_size, padding_idx = self.vocab.pad_token)
        if self.pyramid:
            self.encoder_GRU = []
            self.encoder_linear = []
            for i in range(self.enc_layers - 1):
                self.encoder_GRU.append(nn.GRU(input_size = self.embed_size, hidden_size = self.enc_hidden_size, bidirectional = True))
                self.encoder_linear.append(nn.Linear(in_features = self.enc_hidden_size * 2, out_features = self.embed_size, bias = True))
            self.encoder_GRU.append(nn.GRU(input_size = self.embed_size, hidden_size = self.enc_hidden_size, bidirectional = True))
            self.encoder_linear.append(nn.Linear(in_features = self.enc_hidden_size * 2, out_features = self.enc_hidden_size, bias = True))
            self.encoder_GRU = nn.ModuleList(self.encoder_GRU)
            self.encoder_linear = nn.ModuleList(self.encoder_linear)
        else:
            self.encoder_GRU = nn.GRU(input_size = self.embed_size, hidden_size = self.enc_hidden_size, num_layers = self.enc_layers, bidirectional = True)
            self.encoder_linear = nn.Linear(in_features = self.enc_hidden_size * 2, out_features = self.enc_hidden_size, bias = True) #output of encoder GRU is biderectional, therefore it's enc_hid * 2
            
        self.decoder_GRU = nn.GRU(input_size = self.embed_size, hidden_size = self.dec_hidden_size, num_layers = self.dec_layers)
        
        # Different Attention
        if attention_type == 'Bahdanau':
            self.affine_c = nn.Linear(in_features = self.enc_hidden_size, out_features = self.attention_size, bias = True)
            self.affine_d = nn.Linear(in_features = self.dec_hidden_size, out_features = self.attention_size, bias = True)
            self.attention = self.Bahdanau
        
        elif attention_type == 'dot':
            self.attention = self.Luong_dot
            
        elif attention_type == 'general':
            self.att_general = nn.Linear(in_features = self.enc_hidden_size, out_features = self.dec_hidden_size)
            self.attention = self.Luong_general
            
        elif attention_type == 'concat':
            self.att_concat_1 = nn.Linear(in_features = self.enc_hidden_size + self.dec_hidden_size, out_features = self.attention_size)
            self.att_concat_2 = nn.Linear(in_features = self.attention_size, out_features = 1)
            self.attention = self.Luong_concat
        
        self.output_proj = nn.Linear(in_features = self.dec_hidden_size + self.enc_hidden_size, out_features = self.V_size, bias = True)
        self.dropout = nn.Dropout(p = self.dropout_rate)
        
    def forward(self, source, target):
        """ Calculate sum of Cross-Entropy Loss for the whole sentence.
        @param source (List(List(str))): batch of source sentence represented as words
        @param target (List(List(str))): batch of target sentence represented as words
        @returns CELoss: Cross-Entropy loss of the batch
        """
        source_lengths = [float(len(s)) for s in source]
        #source/target_padded are list of integers
        source_padded = torch.transpose(self.vocab.to_input_tensor(source, self.input_length, self.device),0,1)
        target_padded = torch.transpose(self.vocab.to_input_tensor(target, self.input_length, self.device),0,1)

        X_emb = self.embedding(source_padded)
        Y_emb = self.embedding(target_padded)
        c, dec_init_state = self.encode(X_emb)
        
        o = self.output_proj(self.decode(c, Y_emb, dec_init_state))
        P = F.log_softmax(o, dim=-1)
        
        target_masks = (target_padded != self.vocab['<pad>']).float()
        target_gold_words_log_prob = torch.gather(P, index=target_padded[1:].unsqueeze(-1), dim=-1).squeeze(-1) * target_masks[1:]
         
        CELoss = -target_gold_words_log_prob.sum(dim=0)
        return CELoss
        
    def encode(self, inputs):
        """Encode sentence into a representation of hidden states
        @param inputs: embedded source sentence through learnable word-to-vec embedding layer
        @returns c_t: hidden states from last layer
                dec_init_state: decoder enitial hidden state, taken from last layer of encoder
        """
        #use zero initial hidden state for encoder
        c_t = inputs
        if self.pyramid:
            for j in range(self.enc_layers - 1):
                outputs, h_Tj= self.encoder_GRU[j](c_t)
                f_t = outputs[:, :, :self.enc_hidden_size]
                b_t = outputs[:, :, self.enc_hidden_size:]
                h_t = f_t + b_t
                idx_odd = torch.tensor([2*i+1 for i in range(h_t.shape[0]//2)], device=self.device)
                idx_even = idx_odd - 1
                c_t = torch.cat((torch.index_select(h_t, 0, idx_odd), torch.index_select(h_t, 0, idx_even)),2)
                c_t = torch.tanh(self.encoder_linear[j](c_t))
            outputs, h_Tj = self.encoder_GRU[-1](c_t)
            c_t = torch.tanh(self.encoder_linear[-1](outputs))
        else:
            c_t, h_Tj = self.encoder_GRU(c_t)
            c_t = self.encoder_linear(c_t)
        dec_init_state = h_Tj[-1:, :, :]
        return c_t, dec_init_state
    
    def decode(self, c, Y, dec_init_state):
        """Decode the hidden state into target sentence
        @param c: hidden state from last layer of encoder
        @param Y: decoder input during training, is the true Y from last step
        @param dec_init_state: decoder enitial hidden state
        @returns o: decoder output, to be feed into attention layer
        """
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
        """Decoding by Step, used in beam search and training
        @param input: the decoder output of last step
        @param dec_states_input: decoder hidden state from last step
        @param c: encoded representation from encoder, for attention calculation
        """
        d_t, dec_states_output = self.decoder_GRU(inputs, dec_states_input)
        o_t = self.attention(c, d_t) #o_t.shape==[batch, 1, dec_hid_size + emb_size]
        o_t = self.dropout(o_t)
        return o_t, dec_states_output
    
    def Luong_dot(self, c, d_t):
        """Calculate Luong's dot Attention
        @param c: encoded representation from encoder
        @param d_t: decoded representation at time t
        """
        score = F.softmax(torch.bmm(torch.transpose(d_t, 0, 1), torch.transpose(torch.transpose(c, 0, 1), 1, 2)), dim = 2)
        a_t = torch.transpose(torch.bmm(score,torch.transpose(c, 0, 1)), 0, 1)
        o_t = F.tanh(torch.cat((d_t, a_t), 2))
        return o_t
        
    def Luong_general(self, c, d_t):
        """Calculate Luong's general Attention
        @param c: encoded representation from encoder
        @param d_t: decoded representation at time t
        """
        att_c = self.att_general(c)
        score = F.softmax(torch.bmm(torch.transpose(d_t, 0, 1), torch.transpose(torch.transpose(att_c, 0, 1), 1, 2)), dim = 2)
        a_t = torch.transpose(torch.bmm(score,torch.transpose(c, 0, 1)), 0, 1)
        o_t = F.tanh(torch.cat((d_t, a_t), 2))
        return o_t
        
    def Luong_concat(self, c, d_t):
        """Calculate Luong's concatenate Attention
        @param c: encoded representation from encoder
        @param d_t: decoded representation at time t
        """
        d_dup = torch.cat([d_t] * c.shape[0])
        input_vec = torch.cat((d_dup, c), dim = 2)
        score = self.att_concat_2(self.att_concat_1(input_vec))
        a_t = torch.transpose(torch.bmm(torch.transpose(torch.transpose(score, 0, 1), 1, 2),torch.transpose(c, 0, 1)), 0, 1)
        o_t = F.tanh(torch.cat((d_t, a_t), 2))
        return o_t
    
    def Bahdanau(self, c, d_t):
        """Calculate Bahdanau Attention
        @param c: encoded representation from encoder
        @param d_t: decoded representation at time t
        """
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

        c, dec_init_state = self.encode(X_emb) #c->[1, 1, embed_size], dec_init_state->[1, 1, hid_size]
        h_tm1 = torch.cat([dec_init_state]*self.dec_layers).to(self.device) #h_tm1->[dec_layers, 1, hid_size]
        
        hypotheses = [[self.vocab.start_token]]
        hyp_scores = torch.zeros(len(hypotheses), dtype=torch.float, device=self.device)
        completed_hypotheses = []

        t = 0
        while len(completed_hypotheses) < beam_size and t < max_decoding_time_step:
            t += 1
            hyp_num = len(hypotheses)
            exp_c = c.expand(c.size(0), hyp_num, c.size(2))
            y_tm1 = torch.tensor([[hyp[-1] for hyp in hypotheses]], dtype = torch.long, device=self.device) #y_tm1 -> [hyp_num, emb_size]
            y_t_embed = self.embedding(y_tm1) #y_t_emb -> [1, hyp_num, emb_size]
            o_t, h_t = self.step(y_t_embed, h_tm1, exp_c) #o_t -> [1, hyp_num, out_size], h_t -> [num_layers, hyp_num, dec_hid_size]
            
            # log probabilities over target words
            log_p_t = F.log_softmax(self.output_proj(o_t), dim=-1) #log_p_t->[1, hyp_num, V_size]
            
            live_hyp_num = beam_size - len(completed_hypotheses)
            contiuating_hyp_scores = (hyp_scores.unsqueeze(1).expand_as(log_p_t) + log_p_t).view(-1)
            top_cand_hyp_scores, top_cand_hyp_pos = torch.topk(contiuating_hyp_scores, k=live_hyp_num)
            prev_hyp_ids = top_cand_hyp_pos // len(self.vocab)
            hyp_word_ids = top_cand_hyp_pos % len(self.vocab)

            new_hypotheses = []
            live_hyp_ids = []
            new_hyp_scores = []

            for prev_hyp_id, hyp_word_id, cand_new_hyp_score in zip(prev_hyp_ids, hyp_word_ids, top_cand_hyp_scores):
                prev_hyp_id = prev_hyp_id.item()
                hyp_word_id = hyp_word_id.item()
                cand_new_hyp_score = cand_new_hyp_score.item()

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
            h_tm1 = h_t[:, live_hyp_ids, :]
            hypotheses = new_hypotheses
            hyp_scores = torch.tensor(new_hyp_scores, dtype=torch.float, device=self.device)
        
        if len(completed_hypotheses) == 0:
            s = []
            for idx in hypotheses[0][1:]:
                s.append(self.vocab.id2word(idx))
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
        model = GRU(vocab=vocab, **args)
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
                         enc_layers=self.enc_layers,
                         dec_layers=self.dec_layers,
                         dropout_rate=self.dropout_rate,
                         pyramid=self.pyramid,
                         attention=self.attention),
            'vocab': self.vocab,
            'state_dict': self.state_dict()
        }

        torch.save(params, path)

def test_train():
    vocab = Vocab(embed_size = 4)
    source = read_corpus('src_test.txt', max_len = 400)[:10]
    target = read_corpus('tgt_test.txt', max_len = 400)[:10]
    model = NLC(input_length = 400, embed_size = vocab.embed_size, enc_hidden_size = 4, dec_hidden_size = 4, attention_size = 5, vocab = vocab)
    model(source, target)
    
def test_generate():
    vocab = Vocab()
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

#test_train()
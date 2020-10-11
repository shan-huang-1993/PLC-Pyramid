from utils import pad_idx_tensor
import torch.nn as nn
import torch
import string

class Vocab(object):
    def __init__(self, corpus_file):
        self.word_list = open(corpus_file, 'r').read().split('\n')[:-1]
        self.word2id = dict()
        self.word2id['<pad>'] = 0
        self.word2id['<sos>'] = 1
        self.word2id['<eos>'] = 2
        self.word2id['<unk>'] = 3
        for i, w in enumerate(self.word_list):
            self.word2id[w] = len(self.word2id)
        self.unk_token = self.word2id['<unk>']
        self.start_token = self.word2id["<sos>"]
        self.end_token = self.word2id["<eos>"]
        self.pad_token = self.word2id["<pad>"]
        assert self.start_token+1 == self.end_token
        
        self.index2word = {v: k for k, v in self.word2id.items()}
        
    def __getitem__(self, word):
        #retreive word's index
        return self.word2id[word]
    
    def __contains__(self, word):
        #check if this char is in char list
        return word in self.word2id

    def __setitem__(self, key, value):
        #if one tries to edit the vocabulary
        raise ValueError('vocabulary is readonly')
    
    def __len__(self):
        #number of chars in the vocabulary
        return len(self.word2id)

    def __repr__(self):
        #Representation of VocabEntry to be usedwhen printing the object.
        return 'Vocabulary[size=%d]' % len(self)

    def id2word(self, wordid):
        #Return mapping of index to word. 
        return self.index2word[wordid]
    
    def add(self, word):
        #Add new char to Vocab
        if word not in self:
            wordid = self.word2id[char] = len(self)
            self.idex2word[wordid] = word
            return word
        else:
            return self[word]
            
    def to_input_tensor(self, instances, max_len, device):
        idx_tensor = []
        i = 0
        for instance in instances:
            i += 1
            idx = [self.start_token] + [self.word2id[word] for word in instance]
            idx.append(self.end_token)
            idx_tensor.append(idx)
        idx_tensor = pad_idx_tensor(idx_tensor, self.pad_token, max_len, device)
        return idx_tensor
        
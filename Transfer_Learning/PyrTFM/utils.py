import math
import numpy as np
import torch
from torch.autograd import Variable

def create_src_mask(src, pad, device):
    src_msk = (src != pad).unsqueeze(1)
    
    return src_msk.to(device)
    
def create_tgt_mask(tgt, pad, device):
    tgt_msk = (tgt != pad).unsqueeze(1)
    seq_len = tgt.size(1)
    nopeak_mask = np.triu(np.ones((1, seq_len, seq_len)), k = 1).astype('uint8')
    nopeak_mask = Variable(torch.from_numpy(nopeak_mask) == 0).to(device)
    tgt_msk = tgt_msk & nopeak_mask
    
    return tgt_msk.to(device)
    
def toWordLevel(instance):
    instance = ' '.join(instance.split())
    parser_list_lv1 = ['==', '!=', '&&', '||', '<=', '>=', '__', '\\n']
    parser_list_lv2 = ['!', ';', '=', '+', '-', '&', '%', '*', ':', '.', '|', '/', '(', ')', '{', '}', '[', ']', '<', '>', '\'', '\"', ',', '_', ' ']
    
    parselv1 = []
    while len(instance) > 2:
        i = 0
        while True:
            if instance[i:i+2] in parser_list_lv1:
                if i != 0:
                    parselv1.append(instance[:i])
                parselv1.append(instance[i:i+2])
                instance = instance[i+2:]
                break
            if i == len(instance):
                parselv1.append(instance)
                instance = ''
                break
            i += 1
    parselv2 = []
    for st in parselv1:
        if st not in parser_list_lv1:
            while len(st) > 0:
                i = 0
                while True:
                    if i == len(st):
                        parselv2.append(st)
                        st = ''
                        break
                    if st[i] in parser_list_lv2:
                        if i != 0:
                            parselv2.append(st[:i])
                        parselv2.append(st[i])
                        st = st[i+1:]
                        break
                    i += 1
        else:
            parselv2.append(st)
    return parselv2

def read_corpus(file):
    
    list_of_instances = open(file, 'r').read().split('\n')[:-1]
    out_ins = []
    out_lab = []
    for i in range(len(list_of_instances)):
        label = int(list_of_instances[i][:4])
        instance = toWordLevel(list_of_instances[i][4:])
        out_ins.append(instance)
        out_lab.append(label)
        
    print('%d instances read!                       '%len(out_ins))
    return out_ins, out_lab

def pad_idx_tensor(idx_tensor, pad, max_len, device):
    for i in range(len(idx_tensor)):
        if len(idx_tensor[i]) < max_len:
            idx_tensor[i] += [pad] * (max_len-len(idx_tensor[i]))
        else:
            idx_tensor[i] = idx_tensor[i][:max_len]
    return torch.tensor(idx_tensor, device=device)
    
def batch_iter(data, batch_size, shuffle=False):
    """ Yield batches of source and target sentences reverse sorted by length (largest to smallest).
    @param data (list of (src_sent, tgt_sent)): list of tuples containing source and target sentence
    @param batch_size (int): batch size
    @param shuffle (boolean): whether to randomly shuffle the dataset
    """
    batch_num = math.ceil(len(data) / batch_size)
    index_array = list(range(len(data)))

    if shuffle:
        np.random.shuffle(index_array)

    for i in range(batch_num):
        indices = index_array[i * batch_size: (i + 1) * batch_size]
        examples = [data[idx] for idx in indices]

        examples = sorted(examples, key=lambda e: len(e[0]), reverse=True)
        src_sents = [e[0] for e in examples]
        labels = [e[1] for e in examples]
        
        yield src_sents, labels
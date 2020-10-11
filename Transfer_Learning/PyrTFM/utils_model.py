import torch

def Reinit(model, unif_init = 0.1):
    was_training = model.training
    
    model.eval()
    
    model.encoder.layers[-1].attn.q_linear.weight.data.uniform_(-unif_init, unif_init)
    model.encoder.layers[-1].attn.v_linear.weight.data.uniform_(-unif_init, unif_init)
    model.encoder.layers[-1].attn.k_linear.weight.data.uniform_(-unif_init, unif_init)
    model.encoder.layers[-1].ff.linear_1.weight.data.uniform_(-unif_init, unif_init)
    model.encoder.layers[-1].ff.linear_2.weight.data.uniform_(-unif_init, unif_init)
        
    if was_training:
        model.train()
    return model
    
def ExpandVocab(model, vocab_old, vocab_new):
    pad_vocab = torch.FloatTensor(len(vocab_new) - len(vocab_old), model.d_model).uniform_(-0.1, 0.1)
    model.eval()
    model.encoder.embed.embed.weight.data = torch.cat((model.encoder.embed.embed.weight.data, pad_vocab), 0)
    
    return model
    
def ReInitVocab(model, vocab_new):
    model = model.eval()
    model.encoder.embed.embed.weight.data = orch.FloatTensor(len(vocab_new), model.d_model).uniform_(-0.1, 0.1)
    return model

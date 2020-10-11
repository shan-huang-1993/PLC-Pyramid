import torch
from NLC import NLC
from Vocab_word import Vocab

def modify_enc_dec(model, enc_layers, dec_layers, unif_init = 0.1):
    was_training = model.training
    model.eval()
    with torch.no_grad():
        for layer in enc_layers:
            model.encoder_GRU[layer].weight_hh_l0.data.uniform_(-unif_init, unif_init)
            model.encoder_GRU[layer].weight_ih_l0.data.uniform_(-unif_init, unif_init)
            model.encoder_GRU[layer].weight_hh_l0_reverse.data.uniform_(-unif_init, unif_init)
            model.encoder_GRU[layer].weight_ih_l0_reverse.data.uniform_(-unif_init, unif_init)
        for layer in dec_layers:
            name_ih = 'weight_ih_l' + str(layer)
            name_hh = 'weight_hh_l' + str(layer)
            getattr(model.decoder_GRU, name_hh).data.uniform_(-unif_init, unif_init)
            getattr(model.decoder_GRU, name_ih).data.uniform_(-unif_init, unif_init)
    if was_training:
        model.train()
    return model
            
def test():
    vocab = Vocab_char()
    model = NLC.load('original.bin', vocab = vocab)
    print(model.encoder_GRU[1].weight_hh_l0.data[0][:10])
    print(model.encoder_GRU[1].weight_ih_l0.data[0][:10])
    print(model.encoder_GRU[1].weight_hh_l0_reverse.data[0][:10])
    print(model.encoder_GRU[1].weight_ih_l0_reverse.data[0][:10])
    print(model.decoder_GRU.weight_hh_l1.data[0][:10])
    print(model.decoder_GRU.weight_ih_l1.data[0][:10])
    model = modify_enc_dec(model, enc_layers = [2], dec_layers = [2])
    print(model.encoder_GRU[1].weight_hh_l0.data[0][:10])
    print(model.encoder_GRU[1].weight_ih_l0.data[0][:10])
    print(model.encoder_GRU[1].weight_hh_l0_reverse.data[0][:10])
    print(model.encoder_GRU[1].weight_ih_l0_reverse.data[0][:10])
    print(model.decoder_GRU.weight_hh_l1.data[0][:10])
    print(model.decoder_GRU.weight_ih_l1.data[0][:10])
    
#test()
    
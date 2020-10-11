"""
test_TFM.py: Test trained transformer model

Usage:
    test_TFM.py --model=<file> --src=<file>, --tgt=<file>, --output=<file> --vocab=<file> [options]

Options:
    --help -h                           show this screen
    --model=<file>                      model to be tested
    --src=<file>                        source file
    --tgt=<file>                        target file
    --output=<file>                     output file for comparison, include source, target and output of an instance
    --input-length=<int>                maximum input length of the instance [default: 500]
    --vocab=<file>                      vocabulary file to use
    --cuda=<int>                        device to use
"""

from PLC_Model.TFM import Transformer
from docopt import docopt
from PLC_Model.Vocab_word import Vocab
from PLC_Model.utils import create_src_mask, create_tgt_mask, read_corpus, pad_idx_tensor
import sys
import time

def test_generate(model, src_file, tgt_file, output_file, vocab_file, input_length, device):
    vocab = Vocab(vocab_file)
    model = Transformer.load(model, vocab = vocab).to(device)
    src_sents = read_corpus(src_file, input_length)
    tgt_sents = read_corpus(tgt_file, input_length)
    file = open(output_file,'w+')
    start = time.time()
    
    for i in range(len(src_sents)):
        print('[%d/%d]'%(i, len(src_sents)), file=sys.stdout, end='\r')
        src = src_sents[i:(i+1)]
        src = vocab.to_input_tensor(src, input_length, device = device)
        src_mask = create_src_mask(src, vocab['<pad>'], device = device)
        completed_hypotheses = model.beam_search(src, src_mask, beam_size = 6, max_len = input_length - 1)
        hyp_sents = [hyp.value for hyp in completed_hypotheses]
        print('inputs: ' + ''.join(src_sents[i]), file=file)
        print('\n', file=file)
        print('target: ' + ''.join(tgt_sents[i]), file=file)
        print('\n', file=file)
        for j in range(len(hyp_sents)):
            print('outputs '+ str(j) + ': '+ hyp_sents[j], file=file)
            print('\n', file=file)
        print('\n\n', file=file)
    print('time elapsed: %.2f'%(time.time() - start))
        
def main():
    args = docopt(__doc__)
    if args['--cuda']:
        device = 'cuda:' + args['--cuda']
    else:
        device = 'cpu'
    test_generate(model = args['--model'],
                  src_file = args['--src'],
                  tgt_file = args['--tgt'],
                  output_file = args['--output'],
                  vocab_file = args['--vocab'],
                  input_length = int(args['--input-length']),
                  device = device)
    
if __name__ == '__main__':
    main()

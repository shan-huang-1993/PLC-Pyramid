"""
test_GRU.py: Test trained model

Usage:
    test_GRU.py --model=<file> --src=<file> --tgt=<file> --output=<file> --vocab=<file> [options]

Options:
    --help -h                           show this screen
    --model=<file>                      model to be tested
    --src=<file>                        source file
    --tgt=<file>                        target file
    --output=<file>                     output file for comparison, include source, target and output of an instance
    --input-length=<int>                maximum input length of the instance [default: 700]
    --vocab=<file>                      vocabulary file to use
"""

from PLC_Model.GRU import GRU
from docopt import docopt
from PLC_Model.Vocab_word import Vocab
from PLC_Model.utils import read_corpus, pad_idx_tensor
import sys

def test_generate(model_path, src_file, tgt_file, vocab_file, output_file, input_length):
    vocab = Vocab(vocab_file)
    model = GRU.load(model_path, vocab = vocab)
    input_sents = read_corpus(src_file, input_length)
    target_sents = read_corpus(tgt_file, input_length)
    file = open(output_file,'w+')
    for i in range(len(input_sents)):
        print('[%d/%d]'%(i, len(input_sents)), file=sys.stdout, end='\r')
        input_sent = input_sents[i:(i+1)]
        target_sent = target_sents[i:(i+1)]
        completed_hypotheses = model.beam_search(input_sent)
        hyp_sents = [hyp.value for hyp in completed_hypotheses]
        print('inputs: ' + ''.join(input_sents[i]), file=file)
        print('\n', file=file)
        print('target: ' + ''.join(target_sents[i]), file=file)
        print('\n', file=file)
        for j in range(len(hyp_sents)):
            print('outputs '+ str(j) + ': '+ hyp_sents[j], file=file)
            print('\n', file=file)
        print('\n\n', file=file)
        
def main():
    args = docopt(__doc__)
    test_generate(model_path = args['--model'],
                  src_file = args['--src'],
                  tgt_file = args['--tgt'],
                  vocab_file = args['--vocab'],
                  output_file = args['--output'],
                  input_length = int(args['--input-length']))
    
if __name__ == '__main__':
    main()

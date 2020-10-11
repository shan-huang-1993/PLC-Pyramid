# Pyramid-Seq2Seq-Code-Correction
This is the repo for project: Pyramid structure in sequence to sequence learning for code correction. 

Related publication is available on ArXiv: https://arxiv.org/abs/2001.11367

![alt text](https://github.com/b19e93n/Pyramid-Seq2Seq-Code-Correction/blob/master/Pyramid_Encoder.png)

## Abstract
We apply various seq2seq models on programming language correction tasks on Juliet Test Suite for C/C++ and Java of Software Assurance Reference Datasets(SARD), and achieve 75\%(for C/C++) and 56\%(for Java) repair rates on these tasks. We introduce Pyramid Encoder in these seq2seq models, which largely increases the computational efficiency and memory efficiency, while remain similar repair rate to their non-pyramid counterparts. We successfully carry out error type classification task on ITC benchmark examples (with only 685 code instances) using transfer learning with models pre-trained on Juliet Test Suite, pointing out a novel way of processing small programing language datasets.

## Directories

`/Data`:  
Contains the three dataset we used: Juliet-C, Juliet-Java and ITC benchmark. Example data processing pynotebook for Juliet-Java dataset is uploaded. The complete dataset after pre-processing and a sample train-test splited dataset is included. In our original work, we did a 4-fold cross-validation.

`/PLC_Model`
Contains Model of GRU and Transformer. GRU.py contains implementation of Bahdanau attention, Luong's general, dot and concat attention. Both GRU.py and TFM.py contains implementation of pyramid encoder, that could be toggled on or off.

`/train.py`
run file for training GRU and transformer models

`/test_GRU.py`
script for testing a trained GRU model

`/test_TFM.py`
script for testing a trained Transformer model

`/Transfer_Learning`:  
Transfer Learning on ITC bench mark error type classification with models pre-trained on Juliet Test Suite for C/C++, implementations for both pyramid GRU and pyramid Transformer are given.

The trained models are not included in the repository because of exceeding size. They are available at google drive: 

## Required environment

docopt (0.6.2)
torch (1.6.0)
numpy (1.19.1)
matplotlib (3.3.1)

## Usage
 
### Training a new model

run `python3 train.py -h` for more information.

Example of training a GRU model with bahdanau attention and pyramid encoder on GPU-0:

```
python3 train.py \
--train-src=Data/Juliet-C/src_test0.txt \
--train-tgt=Data/Juliet-C/tgt_test0.txt \
--dev-src=Data/Juliet-C/src_test0.txt \
--dev-tgt=Data/Juliet-C/tgt_test0.txt \
--vocab=Data/Juliet-C/vocab.txt \
--pyramid=1 \
--model-type=Bahdanau \
--cuda=0
```

### Testing a trained model

run `python3 test_GRU.py -h` or `python3 test_TFM.py -h` for more information.

Example of testing a Transformer model (with Pyramid-encoder or not) on GPU-0:

```
python3 test_TFM.py \
--model=model_TFM.bin \
--src=Data/Juliet-C/src_test0.txt \
--tgt=Data/Juliet-C/tgt_test0.txt \
--output=output.txt \
--vocab=Data/Juliet-C/vocab.txt \
--cuda=0
```

Then run metric Evaluation script:

```
python3 evaluation.py
```

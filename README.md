# Pyramid-Seq2Seq-Code-Correction
This is the repo for project: Pyramid structure in sequence to sequence learning for code correction. 

![alt text](https://github.com/b19e93n/Pyramid-Seq2Seq-Code-Correction/blob/master/Pyramid_Encoder.png)

## Abstract
We demonstrate the implementations of pyramid encoders in both multi-layer GRU and Transformer for seq2seq tasks. We apply the models to the code correction task on Juliet Test Suite for C/C++ and Java of Software Assurance Reference Dataset(SARD), successfully repaired 90.1% of faulted code in the test dataset, and show that a pyramid structure can greatly improve memory efficiency and therefore computation efficiency. We successfully carried out error type classification task on ITC benchmark examples (with only 685 code instances) using transfer learning with models pre-trained on Juliet Test Suite, pointing out a novel way of processing small datasets.

## Directories

`/Data_Processing`:  
Contains code used to pre-process the datasets, as well as three original datasets: Juliet C/C++, Juliet Java, ITC Benchmark (for transfer learning)

`/Train_Models`:  
Contains implementations of different seq2seq models, as well as the code of running the training. All default hyper parameters of the models are stated in the paper. If not specified, all models operates on word-level.  
`/Train_Models/PlainGRU`: Plain GRU  
`/Train_Models/PyrGRU`: Pyramid GRU  
`/Train_Models/PyrGRUChar`: Character-level Pyramid GRU  
`/Train_Models/PyrTransformer_ave`: Pyramid Transformer with averaged residual connection  
`/Train_Models/PyrTransformer_ff`: Pyramid Transformer where residual connection is connected with a linear layer to reduce length  
`/Train_Models/Transformer`: Plain Transformer

`/Transfer_Learning`:  
Transfer Learning on ITC bench mark error type classification with models pre-trained on Juliet Test Suite for C/C++, implementations for both pyramid GRU and pyramid Transformer are given.

`/Test_Code`:  
Contains code for test model performance with beam search.

The trained models are not included in the repository because of exceeding size. They are available at google drive: https://drive.google.com/drive/folders/1hIuDWnc-ZX4jb5Q-P_ODnnj-pkd3O4tn?usp=sharing

## How to use

### Data

Data processing files are written as jupyter notebooks and are self-explanatory. Original SARD datasets are included. Sample pre-processed data files we used in the experiments are included under each corresponding directory

### Train Models

Each directory contains model implementation of corresponding model. The default hyper-parameters of `run.py` are set for Juliet Test Suite for C/C++. To train models, please copy corresponding datasets to the model directory and do

```
sh run.sh
```

### Test Models
 
 There are three sub-directories under `Test_Code`, designed for different types of models. GRU models (including Pyramid GRUs), character-level GRU models and Transformer models (including Pyramid Transformer). To use, copy the trained model under corresponding directory, and copy model implementations from their directory in `/Train_Models`. The list of files needs to be copied from there includes:  
 For GRU models:
 ```
 NLC.py, utils.py, Vocab_word.py
 ```
 For Character level GRU models:
 ```
 NLC.py, utils.py, Vocab_char.py
 ```
 For Transformer Models:
 ```
 model_TFM.py, modules.py, utils.py, Vocab_word.py
 ```
 
 Then run 
 ```
 test.sh
 ```
 
 ### Transfer Learning
 
Copy the model pre-trained on Juliet Test Suite for C/C++ under the corresponding directory, then run
 
 ```
 run.sh
 ```
 
 Note that the original model will not be overwritten.
 
 Use `TestModel.py` for evaluating model performance in classification.

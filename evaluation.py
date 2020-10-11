import matplotlib.pyplot as plt
file = open('output.txt', 'r').read().split('\n')
file_0 = []
for i in range(len(file)):
    if file[i] != '':
        file_0.append(file[i])
inputs = []
targets = []
outputs = []
outputs_i = []
for i in range(len(file_0)):
    if file_0[i][:6] == 'inputs':
        inputs.append(file_0[i])
    elif file_0[i][:6] == 'target':
        targets.append(file_0[i])
    elif file_0[i][:7] == 'outputs':
        outputs_i.append(file_0[i])
        if i < len(file_0) - 1:
            if file_0[i+1][:6] == 'inputs':
                outputs.append(outputs_i)
                outputs_i = []
outputs.append(outputs_i)

for i in range(len(inputs)):
    inputs[i] = inputs[i][8:] 
    targets[i] = targets[i][8:]
    for j in range(len(outputs[i])):
        outputs[i][j] = outputs[i][j][11:]

dic = {}

for i in range(len(inputs)):
    if inputs[i] not in dic:
        dic[inputs[i]] = [[targets[i]], [outputs[i]]]
    else:
        dic[inputs[i]][0].append(targets[i])
        dic[inputs[i]][1].append(outputs[i])
key0 = list(dic.keys())[0]
correct_rate = []
x = [1,2,3,4,5]
for j in range(1,6):
    count = 0
    for key in dic.keys():
        for i in range(len(dic[key][1])):
            output_list = dic[key][1][i]
            tgt_list = dic[key][0]
            for k in range(min(j, len(output_list))):
                if output_list[k] in tgt_list:
                    count += 1
                    break
    correct_rate.append(count/len(inputs))

for i in range(5):
    plt.text(i+1, correct_rate[i] - 0.07, "%.2f %%"%(correct_rate[i] * 100), fontsize = 12)

plt.plot(x, correct_rate, 'o')
plt.ylim([0, 1])
plt.xlim([0,6])
plt.xticks([0,1,2,3,4,5],[0,1,2,3,4,5])
plt.xlabel('candidate number')
plt.ylabel('correction rate')
plt.savefig('performance.png')    
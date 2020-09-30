import matplotlib.pyplot as pyplot
import csv
from collections import defaultdict

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv
from matplotlib.pyplot import figure
figure(num=None, figsize=(18, 6), dpi=80, facecolor='w', edgecolor='k')




create = defaultdict(list)
delete = defaultdict(list)
merge = defaultdict(list)
split = defaultdict(list)


with open("results.csv", "r") as f:
    reader = csv.reader(f, delimiter=",")
    for i, line in enumerate(reader):
        oper,ins,outs,prev,t = line
        selected = None
        print(oper)
        if oper == "delete.delete.delete":
            selected = delete
        if oper == "create.create.create":
            selected = create
        if oper == "merge.merge.merge":
            selected = merge
        if oper == "split.split.split":
            selected = split

        selected["{}".format(prev)].append(float(t))

for key,value in create.items():
    create[key] = sum(value) / len(value)
   
for key,value in delete.items():
    delete[key] = sum(value) / len(value)
   
for key,value in merge.items():
    merge[key] = sum(value) / len(value)
   
for key,value in split.items():
    split[key] = sum(value) / len(value)
   

plt.subplot(2, 2, 1)
plt.bar(list(create.keys()), list(create.values()),label="Create")
# plt.axhline(y=600,linewidth=5, color='red')
# plt.yscale("log")
plt.title("Create")

plt.subplot(2, 2, 2)
plt.bar(list(delete.keys()), list(delete.values()))
# plt.yscale("log")
plt.title("Delete")
# plt.axhline(y=600,linewidth=5, color='red')



plt.subplot(2, 2, 3)
plt.bar(list(merge.keys()), list(merge.values()))
# plt.yscale("log")
plt.title("merge")
# plt.axhline(y=600,linewidth=5, color='red')

plt.subplot(2, 2, 4)
plt.bar(list(split.keys()), list(split.values()))
# plt.yscale("log")
plt.title("split")
# plt.axhline(y=600,linewidth=5, color='red')




plt.tight_layout()

plt.savefig("nondet.png")

exit(1)

# labels = ["1,5","5,5"]
# create = [251,-10]
# delete = [2,315]
# merge = [1, 17]
# split = [4, -10]
# # Set position of bar on X axis
# r1 = np.arange(len(create))
# r2 = [x + barWidth for x in r1]
# r3 = [x + barWidth for x in r2]
# r4 = [x + barWidth for x in r3]
 
# # Make the plot
# rects1 = ax.bar(r1, create, width=barWidth, edgecolor='white', label='create')
# rects2 = ax.bar(r2, delete, width=barWidth, edgecolor='white', label='delete')
# rects3 = ax.bar(r3, merge, width=barWidth, edgecolor='white', label='merge')
# rects4 = ax.bar(r4, split, width=barWidth, edgecolor='white', label='split')
 
# # Add xticks on the middle of the group bars
# plt.xlabel('Inputs, Outputs', fontweight='bold')
# plt.xticks([r + barWidth for r in range(len(create))], ['1,5', '5,5', ])
 
# # Create legend & Show graphic
# plt.legend()
# def autolabel(rects):
#     """Attach a text label above each bar in *rects*, displaying its height."""
#     for rect in rects:
#         height = rect.get_height()
#         ax.annotate('{}'.format(height),
#                     xy=(rect.get_x() + rect.get_width() / 2, height),
#                     xytext=(0, 3),  # 3 points vertical offset
#                     textcoords="offset points",
#                     ha='center', va='bottom')

# autolabel(rects1)
# autolabel(rects2)
# autolabel(rects3)
# autolabel(rects4)


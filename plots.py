import matplotlib.pyplot as pyplot
import csv
from collections import defaultdict

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv
from matplotlib.pyplot import figure
import random



def make_figure(name="results/experiments{}",number=1):
    filename = name.format(number) + ".csv"
    fig = figure(num=None, figsize=(18, 6), dpi=80, facecolor='w', edgecolor='k')
    fig.suptitle('Timeout 350secs | 0.2 prevalence', fontsize=16)



    create = defaultdict(list)
    delete = defaultdict(list)
    merge = defaultdict(list)
    split = defaultdict(list)


    with open(filename, "r") as f:
        reader = csv.reader(f, delimiter=",")
        for _, line in enumerate(reader):
            oper,ins,outs,prev,t,status = line
            selected = None
            if "delete" in oper:
                selected = delete
            if "create" in oper:
                selected = create
            if "merge" in oper:
                selected = merge
            if "split" in oper:
                selected = split

            

            selected["{},{}".format(ins,outs)].append(float(t))

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
    plt.axhline(y=350,linewidth=1, color='red',label="Timeout")
    # # plt.yscale("symlog")
    plt.ylabel("T in seconds")
    plt.xlabel("Inputs, Outputs")
    plt.ylim(-10, 400)
    plt.title("Create")

    plt.subplot(2, 2, 2)
    plt.bar(list(delete.keys()), list(delete.values()))
    # # plt.yscale("symlog")
    plt.title("Delete")
    plt.axhline(y=350,linewidth=1, color='red',label="Timeout")
    plt.ylim(-10, 400)
    plt.ylabel("T in seconds")
    plt.xlabel("Inputs, Outputs")



    plt.subplot(2, 2, 3)
    plt.bar(list(merge.keys()), list(merge.values()))
    # # plt.yscale("symlog")
    plt.title("merge")
    plt.axhline(y=350,linewidth=1, color='red',label="Timeout")
    plt.ylim(-10, 400)
    plt.ylabel("T in seconds")
    plt.xlabel("Inputs, Outputs")


    plt.subplot(2, 2, 4)
    plt.bar(list(split.keys()), list(split.values()))
    # # plt.yscale("symlog")
    plt.title("split")
    plt.axhline(y=350,linewidth=1, color='red',label="Timeout")
    plt.ylim(-10, 400)
    plt.ylabel("T in seconds")
    plt.xlabel("Inputs, Outputs")




    
    plt.tight_layout()

    plt.savefig(name.format(number) + ".png")


def make_scatter(name="results/experiments{}",number=1):
    filename = name.format(number) + ".csv"
    fig = figure(num=None, figsize=(18, 6), dpi=80, facecolor='w', edgecolor='k')
    fig.suptitle('Timeout 350secs | 0.2 prevalence', fontsize=16)



    create = defaultdict(list)
    delete = defaultdict(list)
    merge = defaultdict(list)
    split = defaultdict(list)


    with open(filename, "r") as f:
        reader = csv.reader(f, delimiter=",")
        for _, line in enumerate(reader):
            oper,ins,outs,prev,t,status = line
            selected = None
            if "delete" in oper:
                selected = delete
            if "create" in oper:
                selected = create
            if "merge" in oper:
                selected = merge
            if "split" in oper:
                selected = split

            
            if float(t) < 0:
                t = -50

            selected["{}.{}".format(ins,outs)].append(float(t))

   
    

    plt.subplot(2, 2, 1)

    for key,value in create.items():
        i = 0
        for val in value:
            if val < 0:
                val -= 30 * i 
                i += 1
            plt.scatter(key,val)

    plt.axhline(y=0,linewidth=1, color='black',label="zero")
    # plt.yscale("symlog")
    plt.ylabel("T in seconds")
    plt.xlabel("Inputs, Outputs")
    plt.xticks(["10,30,50,80"])
    plt.ylim(-150, 400)
    plt.title("Create")



    plt.subplot(2, 2, 2)
    for key,value in delete.items():
        i = 0
        for val in value:
            if val < 0:
                val -= 30 * i 
                i += 1
            plt.scatter(key,val)
    # plt.yscale("symlog")
    plt.title("Delete")
    plt.axhline(y=0,linewidth=1, color='black',label="zero")
    plt.ylabel("T in seconds")
    # plt.xticks([10,30,50,80])
    plt.ylim(-150, 400)

    plt.xlabel("Inputs, Outputs")



    plt.subplot(2, 2, 3)
    for key,value in merge.items():
        i = 0
        for val in value:
            if val < 0:
                val -= 30 * i 
                i += 1
            plt.scatter(key,val)
    # plt.yscale("symlog")
    plt.title("merge")
    plt.axhline(y=0,linewidth=1, color='black',label="zero")
    plt.ylabel("T in seconds")
    # plt.xticks([10,30,50,80])
    plt.ylim(-150, 400)

    plt.xlabel("Inputs, Outputs")


    plt.subplot(2, 2, 4)
    for key,value in split.items():
        i = 0
        for val in value:
            if val < 0:
                val -= 30 * i 
                i += 1
            plt.scatter(key,val)
    # plt.yscale("symlog")
    plt.title("split")
    plt.axhline(y=0,linewidth=1, color='black',label="zero")
    plt.ylabel("T in seconds")
    # plt.xticks([10,30,50,80])
    plt.ylim(-150, 400)

    plt.xlabel("Inputs, Outputs")




    
    plt.tight_layout()

    plt.savefig(name.format(number) + "scatter.png")

if __name__ == "__main__":
    # make_figure(number=1)
    # make_scatter(number=1)

    # make_figure(number=2)
    # make_scatter(number=2)

    make_figure(number=3)
    make_scatter(number=3)

    # make_figure(number=4)
    # make_scatter(number=4)
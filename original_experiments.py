import generator
import stateyasper
import sys

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np



def plot(x,y,z,c,experimentNumber):
    x =np.asarray(x)
    y =np.asarray(y)
    z =np.asarray(z)
    

    c =np.asarray(c)

    fig = plt.figure()
    ax = fig.gca(projection='3d')
    

    img = ax.scatter(x, y, z, c=c, cmap=plt.cool())

    ax.set_xlabel('Inputs')
    ax.set_ylabel('Outputs')
    ax.set_zlabel('$P_{expected}$')
    
    cbrar = fig.colorbar(img)
    cbrar.set_label('$P_{real}$')

    # ax.legend()
    plt.title("Relation of inputs, outputs and non-determinism")



    outF = open("results/experiment2.txt","w")
    sys.stdout = outF

    print("inputs,outputs,prevalence,nondeterminism")
    for i,_ in enumerate(x):
        print("{},{},{:04.2f},{:06.4f}".format(x[i],y[i],z[i],c[i]))



    plt.savefig('results/experiment4.png'.format(experimentNumber))
    plt.show()


def plot2d(x,y,number):

    linex = np.arange(2,200,2)
    liney = generator.max_prevalence(linex,linex)

    fig = plt.figure()
    ax = fig.gca()
    

    img = ax.scatter(x, y,  c="r")
    # ax.plot(linex,y,c="g")
    ax.plot(linex,liney,ls="--")
    ax.set_xlabel('Inputs/Outputs')
    ax.set_ylabel('Prevalence')
   
    ax.legend(['Theoretical Limit','Computed Prevalence of Non-Determinism'])

    plt.title("Experiment: Maximum Observed Prevalence of Non-Determinism".format(number))

    outF = open("results/experiment{}.txt".format(number),"w")
    sys.stdout = outF

    print("Inputs and Outputs,Maximum Observed Prevalence,theoretical limit")
    for i,_ in enumerate(x):
        print("{},{:06.4f},{}".format(x[i],y[i],liney[i]))


    plt.savefig('results/experiment{}.png'.format(number))
  

def experiment_1_probability():
    # equal number inputs outputs 
    
    x = np.arange(2,200,4)
    z = np.array([])
  

    for val in x:
        print(val)
        temp = 0
        for _ in range(0,200):

            statemachine  = generator.generate(generator.random_generator(val,val,1.00))
            temp = max(generator.determine_non_determinism(statemachine),temp)
        z = np.append(z,temp)
    plot2d(x,z,"Maximum Observed Prevalence of Non-Determinism")


def experiment_1():
      
    x = np.arange(2,100,4)
    z = np.array([])
    countaverage = 10

    for val in x:
        print(val)
        sumprevalence = 0
        for _ in range(0,countaverage):

            statemachine  = generator.generate(generator.random_generator(val,val,1.00))
            sumprevalence += generator.determine_non_determinism(statemachine)
        z = np.append(z,sumprevalence/countaverage)
    plot2d(x,z,"Average Maximum Prevalence of Non-Determinism")

def experiment_2():
    inputs = np.array([2,15,20,30,50,80]) # 2,22,42, etc. FIXEd
    outputs = np.arange(2,150,1) #  NON fixed
    prevalence = np.arange(0.1,1.00,0.1) # FIXED
    counteraverage = 15
    

   
    prev = 0.6
    # prev = 0.2
    # prev = 0.4
    # prev = 0.8
        

    
    plt.plot([0,150],[prev,prev],c="black",label="Supplied Prevalence")

    for inp in inputs:
        print(inp)
        nondeterminism = np.array([]) 
        for outp in outputs:
            sumprevalence = 0
            for _ in range(0,counteraverage):
                statemachine  = generator.random_generator(inp,outp,prev)
                sumprevalence += generator.determine_non_determinism(statemachine)
            nondeterminism = np.append(nondeterminism,sumprevalence/counteraverage)
            
        plt.plot(outputs,nondeterminism,label="Inputs = {}".format(inp,prev))   

    plt.ylim(0.0,1.0)
    plt.xlabel("Outputs")
    plt.ylabel("Measured Prevalence")
    plt.legend()
    plt.title("{} Prevalence of Non-Determinism".format(prev))
    plt.savefig("results/Tester{}.png".format(prev))
  
    
    


if __name__ == "__main__":
    # experiment_1()
    # experiment_1_probability()
    experiment_2()
    
    
import modifications
import generator
import conversion
import stateyasper
import subprocess
import time
import random
from subprocess import STDOUT, check_output
from collections import defaultdict
from jinja2 import Environment, FileSystemLoader


LOCATION_COMMA = "/home/scripts/comma-cmd.jar" 
LOCATION_FIONA = "" # Can leave this blank just add to path

def create_ar_file():
    ar_file_input = modifications.ar_file_input
    ar_file_output = modifications.ar_file_output
    env = Environment(loader=FileSystemLoader('templates'))
    file_ar = env.get_template('ar.jinja').render(**locals())


    with open('test/{}.ar'.format("ZARFILE"), 'w') as f:
        print(file_ar, file=f)  
        

    # Now should be 2 directories with V1 and V2
    subprocess.call(['java', '-jar', LOCATION_COMMA,"-l","test/v1/V1.prj"])
    subprocess.call(['java', '-jar', LOCATION_COMMA,"-l","test/v2/V2.prj"])



def experiment_1(prevalence=0.2):
    """This runs experiment set 1 and writes it to the file
    "experiments1.csv" formatted as
    "Operation, Inputs, Outputs, Prevalence, Time in seconds"
    """
    # INPUT_RANGE = [10,30,50,80]
    INPUT_RANGE = [50,80]
    DATAPOINT_SAMPLES = 7
    AMOUNT_MODIFICATIONS = 1
    TIMEOUT = 350
    filename = "experiments1.csv"
    
    
    # possible_modifications = [modifications.delete,modifications.create,modifications.merge,modifications.split]
    possible_modifications = [modifications.split]
    for modification in possible_modifications:
        for inout in INPUT_RANGE:
            for _ in range(DATAPOINT_SAMPLES):
                
                modifications.ar_file_input = defaultdict(list)
                modifications.ar_file_output =  defaultdict(list)
                modifications.already_modified = []
                
                try:
                    rules = generator.random_generator(inout,inout,prevalence)
                    statemachine = generator.generate(rules)
                    modifications.populate_ar_file(statemachine)
                    
                    # Attempt to perform modifications
                    statemachine_modified = False
                    while not statemachine_modified:
                        statemachine_modified, performed_modifications = modifications.perform_modifications(statemachine,possible_modifications=[modification],amount=AMOUNT_MODIFICATIONS)
            
                    # Genereates the COMMA files hardcoded directory
                    conversion.generate_conversion(statemachine,"V1","test/v1/")
                    conversion.generate_conversion(statemachine_modified,"V2","test/v2/")

                    # Create AR file and run CMD Comma
                    create_ar_file()
                
                
                    # Should now have directories containing files
                    # TODO: Run FIONA here with TIME
                    # fiona -t adapter SERVER.owfn CLIENT.owfn -a ARFILE.ar
                    with open(filename, 'a+') as f:
                        
                        time_start = time.time()
                        outpu = subprocess.check_output(['fiona',  "-p", "no-dot","-p" ,"no-png",'-t',"smalladapter", "test/v1/src-gen/DYNAMICS/openNetTask/V1__1_0__Server.owfn","test/v2/src-gen/DYNAMICS/openNetTask/V2__1_0__Client.owfn","-a","test/ZARFILE.ar"],timeout=TIMEOUT)
                        elapsed_time = time.time() - time_start
                        
                        # CHeck if an adapter was created even
                        outpu = outpu.decode("utf-8")
                        print(outpu)
                        if "Cannot synthesize a partner for a net" in outpu or "memory exhausted" in outpu:
                            elapsed_time = -1
                           
                        
                        print("{},{},{},{},{},(good)".format(".".join(performed_modifications),inout,inout,prevalence,elapsed_time),file=f)
                  
                except Exception as e:
                    # How to end up here:
                    # -- If it was timed out after subprocess call
                    # -- Non zero exit status that is memory exhaustion
                    

                    if "timed out after" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(timed_out)".format(".".join(performed_modifications),inout,inout,prevalence),file=f)
                       

                    elif "non-zero exit status 5" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(exhausted)".format(".".join(performed_modifications),inout,inout,prevalence),file=f)
                        # This was a memory exhaustion
                        
def experiment_2(prevalence=0.2):
    """This runs experiment set 2 and writes it to the file
    "experiments2.csv" formatted as
    "Operation, Inputs, Outputs, Prevalence, Time in seconds"
    """
    INPUT_RANGE = [(10,30),(30,10),(10,50),(50,10),(30,50),(50,30)]
    DATAPOINT_SAMPLES = 7
    AMOUNT_MODIFICATIONS = 1
    TIMEOUT = 350
    filename = "experiments2.csv"
    
    
    possible_modifications = [modifications.delete,modifications.create,modifications.merge,modifications.split]
    for modification in possible_modifications:
        for inout in INPUT_RANGE:
            inputs = inout[0]
            output = inout[1]

            for _ in range(DATAPOINT_SAMPLES):
                
                modifications.ar_file_input = defaultdict(list)
                modifications.ar_file_output =  defaultdict(list)
                modifications.already_modified = []
                
                try:
                    rules = generator.random_generator(inputs,output,prevalence)
                    statemachine = generator.generate(rules)
                    modifications.populate_ar_file(statemachine)
                    
                    # Attempt to perform modifications
                    statemachine_modified = False
                    while not statemachine_modified:
                        statemachine_modified, performed_modifications = modifications.perform_modifications(statemachine,possible_modifications=[modification],amount=AMOUNT_MODIFICATIONS)
            
                    # Genereates the COMMA files hardcoded directory
                    conversion.generate_conversion(statemachine,"V1","test/v1/")
                    conversion.generate_conversion(statemachine_modified,"V2","test/v2/")

                    # Create AR file and run CMD Comma
                    create_ar_file()
                
                
                    # Should now have directories containing files
                    # TODO: Run FIONA here with TIME
                    # fiona -t adapter SERVER.owfn CLIENT.owfn -a ARFILE.ar
                    with open(filename, 'a+') as f:
                        
                        time_start = time.time()
                        outpu = subprocess.check_output(['fiona',  "-p", "no-dot","-p" ,"no-png",'-t',"smalladapter", "test/v1/src-gen/DYNAMICS/openNetTask/V1__1_0__Server.owfn","test/v2/src-gen/DYNAMICS/openNetTask/V2__1_0__Client.owfn","-a","test/ZARFILE.ar"],timeout=TIMEOUT)
                        elapsed_time = time.time() - time_start
                        
                        # CHeck if an adapter was created even
                        outpu = outpu.decode("utf-8")
                        print(outpu)
                        if "Cannot synthesize a partner for a net" in outpu or "memory exhausted" in outpu:
                            elapsed_time = -1
                           
                        
                        print("{},{},{},{},{},(good)".format(".".join(performed_modifications),inputs,output,prevalence,elapsed_time),file=f)
                  
                except Exception as e:
                    # How to end up here:
                    # -- If it was timed out after subprocess call
                    # -- Non zero exit status that is memory exhaustion
                    

                    if "timed out after" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(timed_out)".format(".".join(performed_modifications),inputs,output,prevalence),file=f)
                       

                    elif "non-zero exit status 5" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(exhausted)".format(".".join(performed_modifications),inputs,output,prevalence),file=f)
                        # This was a memory exhaustion
                        
                    
                
                           
def experiment_3(prevalence=0.2):
    """This runs experiment set 1 and writes it to the file
    "experiments3.csv" formatted as
    "Operation, Inputs, Outputs, Prevalence, Time in seconds"
    """
    INPUT_RANGE = [10,30,50,80]
    DATAPOINT_SAMPLES = 7
    AMOUNT_MODIFICATIONS = 3
    TIMEOUT = 350
    filename = "experiments3.csv"

    TRIES = 10
    
    
    # possible_modifications = [modifications.delete,modifications.create,modifications.merge,modifications.split]
    possible_modifications = [modifications.create,modifications.merge,modifications.split]
    for modification in possible_modifications:
        for inout in INPUT_RANGE:
            x = 0
            n_try = TRIES 
            while x < DATAPOINT_SAMPLES:
                x += 1
                modifications.ar_file_input = defaultdict(list)
                modifications.ar_file_output =  defaultdict(list)
                modifications.already_modified = []
                
                elapsed_time = None
                try:
                    rules = generator.random_generator(inout,inout,prevalence)
                    statemachine = generator.generate(rules)
                    modifications.populate_ar_file(statemachine)
                    
                    # Attempt to perform modifications
                    statemachine_modified = False
                    while not statemachine_modified:
                        statemachine_modified, performed_modifications = modifications.perform_modifications(statemachine,possible_modifications=[modification],amount=AMOUNT_MODIFICATIONS)
            
                    # Genereates the COMMA files hardcoded directory
                    conversion.generate_conversion(statemachine,"V1","test/v1/")
                    conversion.generate_conversion(statemachine_modified,"V2","test/v2/")

                    # Create AR file and run CMD Comma
                    create_ar_file()
                
                
                    # Should now have directories containing files
                    # TODO: Run FIONA here with TIME
                    # fiona -t adapter SERVER.owfn CLIENT.owfn -a ARFILE.ar
                    with open(filename, 'a+') as f:
                        
                        time_start = time.time()
                        outpu = subprocess.check_output(['fiona',  "-p", "no-dot","-p" ,"no-png",'-t',"smalladapter", "test/v1/src-gen/DYNAMICS/openNetTask/V1__1_0__Server.owfn","test/v2/src-gen/DYNAMICS/openNetTask/V2__1_0__Client.owfn","-a","test/ZARFILE.ar"],timeout=TIMEOUT)
                        elapsed_time = time.time() - time_start
                        
                        # CHeck if an adapter was created even
                        outpu = outpu.decode("utf-8")
                        print(outpu)
                        if "Cannot synthesize a partner for a net" in outpu or "memory exhausted" in outpu:
                            elapsed_time = -1
                            if n_try > 0:
                                x -= 1
                                n_try -= 1
                        
                        print("{},{},{},{},{},(good)".format(".".join(performed_modifications),inout,inout,prevalence,elapsed_time),file=f)
                  
                except Exception as e:
                    # How to end up here:
                    # -- If it was timed out after subprocess call
                    # -- Non zero exit status that is memory exhaustion
                   

                    if "timed out after" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(timed_out)".format(".".join(performed_modifications),inout,inout,prevalence),file=f)
                       

                    elif "non-zero exit status 5" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(exhausted)".format(".".join(performed_modifications),inout,inout,prevalence),file=f)
                        # This was a memory exhaustion      
                    elif n_try > 0:
                        x -= 1
                        n_try -= 1
                if elapsed_time != None:
                    n_try = TRIES
       
                

def experiment_4(prevalence=0.2):
    """This runs experiment set 1 and writes it to the file
    "experiments4.csv" formatted as
    "Operation, Inputs, Outputs, Prevalence, Time in seconds"
    """
    INPUT_RANGE = [30,50,80]
    DATAPOINT_SAMPLES = 7
    AMOUNT_MODIFICATIONS = 5
    TIMEOUT = 350
    filename = "experiments4.csv"
    
    
    TRIES = 10
    
    
    possible_modifications = [modifications.delete,modifications.create,modifications.merge,modifications.split]
    possible_modifications = [modifications.merge,modifications.split]
    for modification in possible_modifications:
        for inout in INPUT_RANGE:
            x = 0
            n_try = TRIES 
            while x < DATAPOINT_SAMPLES:
                x += 1
                modifications.ar_file_input = defaultdict(list)
                modifications.ar_file_output =  defaultdict(list)
                modifications.already_modified = []
                
                elapsed_time = None
                try:
                    rules = generator.random_generator(inout,inout,prevalence)
                    statemachine = generator.generate(rules)
                    modifications.populate_ar_file(statemachine)
                    
                    # Attempt to perform modifications
                    statemachine_modified = False
                    while not statemachine_modified:
                        statemachine_modified, performed_modifications = modifications.perform_modifications(statemachine,possible_modifications=[modification],amount=AMOUNT_MODIFICATIONS)
            
                    # Genereates the COMMA files hardcoded directory
                    conversion.generate_conversion(statemachine,"V1","test/v1/")
                    conversion.generate_conversion(statemachine_modified,"V2","test/v2/")

                    # Create AR file and run CMD Comma
                    create_ar_file()
                
                
                    # Should now have directories containing files
                    # TODO: Run FIONA here with TIME
                    # fiona -t adapter SERVER.owfn CLIENT.owfn -a ARFILE.ar
                    with open(filename, 'a+') as f:
                        
                        time_start = time.time()
                        outpu = subprocess.check_output(['fiona',  "-p", "no-dot","-p" ,"no-png",'-t',"smalladapter", "test/v1/src-gen/DYNAMICS/openNetTask/V1__1_0__Server.owfn","test/v2/src-gen/DYNAMICS/openNetTask/V2__1_0__Client.owfn","-a","test/ZARFILE.ar"],timeout=TIMEOUT)
                        elapsed_time = time.time() - time_start
                        
                        # CHeck if an adapter was created even
                        outpu = outpu.decode("utf-8")
                        print(outpu)
                        if "Cannot synthesize a partner for a net" in outpu or "memory exhausted" in outpu:
                            elapsed_time = -1
                            if n_try > 0:
                                x -= 1
                                n_try -= 1
                        
                        print("{},{},{},{},{},(good)".format(".".join(performed_modifications),inout,inout,prevalence,elapsed_time),file=f)
                  
                except Exception as e:
                    # How to end up here:
                    # -- If it was timed out after subprocess call
                    # -- Non zero exit status that is memory exhaustion
                   

                    if "timed out after" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(timed_out)".format(".".join(performed_modifications),inout,inout,prevalence),file=f)
                                               

                    elif "non-zero exit status 5" in str(e):
                        with open(filename, 'a+') as f:
                            print("{},{},{},{},-1,(exhausted)".format(".".join(performed_modifications),inout,inout,prevalence),file=f)
                        # This was a memory exhaustion    
                    else:
                        x -= 1
                if elapsed_time != None:
                    n_try = TRIES
       
                



if __name__ == "__main__":
    # experiment_1()
    print("done1")
    # experiment_2()
    print("done2")
    # experiment_3() # modifications amount is 3
    print("done3")
    experiment_4()
    print("Done4")
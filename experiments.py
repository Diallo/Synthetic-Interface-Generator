import modifications
import generator
import conversion
import stateyasper
import subprocess
import time
import random
from subprocess import STDOUT, check_output

LOCATION_COMMA = "/home/scripts/comma-cmd.jar" 
LOCATION_FIONA = "" # Can leave this blank just add to path



if __name__ == "__main__":
   
    # possible_modifications = [modifications.merge,modifications.split]
    # possible_modifications = [modifications.delete,modifications.create,modifications.merge,modifications.split]
    # possible_modifications = [modifications.merge,modifications.split]
    possible_modifications = [modifications.delete]


    while len(possible_modifications):
        selected_modification =  [possible_modifications.pop(0)]

        # input_list =  [(x,x) for x in [30]]
        # input_list =  [(10,5),(10,30),(10,50),(25,5),(25,30),(25,50),(35,5),(35,30),(35,50)] # in out  (inputs same > Outputs increase)
        input_list =  [(10,10)] # in out  (inputs same > Outputs increase)
        # input_list =  [(35,5),(35,30),(35,50)] # in out  (inputs same > Outputs increase)
        
        while len(input_list):
            tup = input_list.pop(0)
            inputs = tup[0]
            outputs = tup[1]
            prevalence = 0.2

            # Do 3 iterations
            x = 0
            # data-points
            datapoints = 5
            while x < datapoints:
                try:
                    # Generation the statemachine (Original)
                    rules = generator.random_generator(inputs,outputs,prevalence)
                    statemachine = generator.generate(rules)
                    # Generatiosns the default AR 
                    modifications.populate_ar_file(statemachine)
                

                    
                    # Try to perform a modification
                    statemachine_modified = False
                    wrong = 0
                    while not statemachine_modified:
                        statemachine_modified = modifications.perform_modifications(statemachine,possible_modifications=selected_modification)
                        wrong += 1

                






                    conversion.generate_conversion(statemachine,"V1","test/v1/")
                    conversion.generate_conversion(statemachine_modified,"V2","test/v2/")

                    # # TEMPORARY TODO (document) CREATE THE AR
                    ar_file_input = modifications.ar_file_input
                    ar_file_output = modifications.ar_file_output
                    from jinja2 import Environment, FileSystemLoader
                    env = Environment(loader=FileSystemLoader('templates'))
                    file_ar = env.get_template('ar.jinja').render(**locals())


                    with open('test/{}.ar'.format("ZARFILE"), 'w+') as f:
                        print(file_ar, file=f)  
                    

                    # Now should be 2 directories with V1 and V2
                    subprocess.call(['java', '-jar', LOCATION_COMMA,"-l","test/v1/V1.prj"])
                    subprocess.call(['java', '-jar', LOCATION_COMMA,"-l","test/v2/V2.prj"])


                    # Should now have directories containing files
                    # TODO: Run FIONA here with TIME
                    # fiona -t adapter SERVER.owfn CLIENT.owfn -a ARFILE.ar
                    with open('results.csv', 'a+') as f:
                        print("{},{},{}".format(selected_modification[0].__name__,inputs,outputs,prevalence))
                        
                        time_start = time.time()
                        outpu = subprocess.check_output(['fiona', '-t',"smalladapter", "test/v1/src-gen/DYNAMICS/openNetTask/V1__1_0__Server.owfn","test/v2/src-gen/DYNAMICS/openNetTask/V2__1_0__Client.owfn","-a","test/ZARFILE.ar"],timeout=300)
                        elapsed_time = time.time() - time_start
                        
                        # CHeck if an adapter was created even
                        outpu = outpu.decode("utf-8")
                        print(outpu)
                        if "Cannot synthesize a partner for a net" in outpu or "memory exhausted" in outpu:
                            elapsed_time = -1
                            x -= 1
                       
                        print("{},{},{},{},{}".format(selected_modification[0].__name__,inputs,outputs,prevalence,elapsed_time),file=f)
                    x += 1
                except Exception as e:
                    # How to end up here:
                    # -- If it was timed out after subprocess call
                    # -- Non zero exit status that is memory exhaustion
                    

                    if "timed out after" in str(e):
                        with open('results.csv', 'a+') as f:
                            print("{},{},{},{},-1,(timed_out)".format(selected_modification[0].__name__,inputs,outputs,prevalence),file=f)
                        x += 1

                    elif "non-zero exit status 5" in str(e):
                        with open('results.csv', 'a+') as f:
                            print("{},{},{},{},-1,(exhausted)".format(selected_modification[0].__name__,inputs,outputs,prevalence),file=f)
                        # This was a memory exhaustion
                        
                    
                    # TODO: infinite loop might occur
        
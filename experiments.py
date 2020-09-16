import modifications
import generator
import conversion
import stateyasper
import subprocess
import time
import random
LOCATION_COMMA = "/home/scripts/comma-cmd.jar" 
LOCATION_FIONA = "" # Can leave this blank just add to path



if __name__ == "__main__":
    input_list = [5,10,20]
    output_list = [5,10,20]
    prevalence_list = [0.2,0.2,0.2]
    possible_modifications = [modifications.delete,modifications.create,modifications.merge,modifications.split]

    while len(input_list):
        inputs = input_list.pop(0)
        outputs = output_list.pop(0)
        prevalence = prevalence_list.pop(0)

        while len(possible_modifications):
            selected_modification =  [possible_modifications.pop(0)]
            try:
                rules = generator.random_generator(inputs,outputs,prevalence)
                statemachine = generator.generate(rules)
                modifications.populate_ar_file(statemachine)
            

                

                statemachine_modified = False
                wrong = 0
                while not statemachine_modified:
                    statemachine_modified = modifications.perform_modifications(statemachine,possible_modifications=selected_modification)
                    wrong += 1

            






                conversion.generate_conversion(statemachine,"V1","test/v1/")
                conversion.generate_conversion(statemachine_modified,"V2","test/v2/")

                # # TEMPORARY TODO
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
                time_start = time.time()
                with open('results.csv', 'a+') as f:
                    time_start = time.time()
                    subprocess.call(['fiona', '-t',"adapter", "test/v1/src-gen/DYNAMICS/openNetTask/V1__1_0__Server.owfn","test/v2/src-gen/DYNAMICS/openNetTask/V2__1_0__Client.owfn","-a","test/ZARFILE.ar"])
                    elapsed_time = time.time() - time_start

                    print("{},{},{},{},{}".format(selected_modification[0].__name__,inputs,outputs,prevalence,elapsed_time),file=f)
                    
            except Exception as e:
                pass
import modifications
import generator
import conversion
import stateyasper





if __name__ == "__main__":
    inputs = 5
    outputs = 5
    prevalence = 0.4


    rules = generator.random_generator(inputs,outputs,prevalence)
    statemachine = generator.generate(rules)
    modifications.populate_ar_file(statemachine)


    

    statemachine_modified = False
    wrong = 0
    while not statemachine_modified:
        statemachine_modified = modifications.perform_modifications(statemachine)
        wrong += 1

    print(wrong)






    conversion.generate_conversion(statemachine,"V1")
    conversion.generate_conversion(statemachine_modified,"V2")

    # # TEMPORARY TODO
    from jinja2 import Environment, FileSystemLoader
    env = Environment(loader=FileSystemLoader('templates'))
    file_ar = env.get_template('ar.jinja').render(**locals())


    with open('{}.ar'.format("ZARFILE"), 'w+') as f:
        print(file_ar, file=f)  
    
        
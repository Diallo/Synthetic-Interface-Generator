#!/usr/bin/python3

import generator
import sys
from jinja2 import Environment, FileSystemLoader





def replace_final(statemachine):
    # TODO copy here

    found = None
    for place in statemachine.states:
        if place == statemachine.FinalState:
            found = place
    
    for transition in statemachine.transitions:
        if transition.end == found:
            
            transition.end = statemachine.BeginState 

    
    statemachine.states.remove(found)

    print(found)
    print(statemachine.FinalState)
    return statemachine

def generate_conversion(statemachine,output_file="generation",):

    env = Environment(loader=FileSystemLoader('templates'))



    statemachine = replace_final(statemachine)


    file_interface = env.get_template('interface.jinja')
    file_prj = env.get_template('prj.jinja')
    file_signature = env.get_template('signature.jinja')
    file_types = env.get_template('types.jinja')
    file_ar = env.get_template('ar.jinja')
    file_param = env.get_template('params.jinja')

    file_signature = file_signature.render(**locals())
    file_interface = file_interface.render(**locals())
    file_prj = file_prj.render(**locals())
    file_types = file_types.render(**locals())
    file_ar = file_ar.render(**locals())
    file_param = file_param.render(**locals())
    
    
    with open('{}.signature'.format(output_file), 'w+') as f:
        print(file_signature, file=f)  

    with open('{}.interface'.format(output_file), 'w+') as f:
        print(file_interface, file=f)  

    with open('{}.prj'.format(output_file), 'w+') as f:
        print(file_prj, file=f)  

    with open('{}.types'.format(output_file), 'w+') as f:
        print(file_types, file=f)  

    with open('{}.ar'.format(output_file), 'w+') as f:
        print(file_ar, file=f)  

    with open('{}.ar'.format(output_file), 'w+') as f:
        print(file_param, file=f)  
   
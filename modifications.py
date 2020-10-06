"""
File: modifications.py
Description: Allows a statemachine to have modifications to be performed upon it.

Usage: Import "modifications.perform_modifications" and call the function. 
       See: Function documentation.
    
"""


# TODO for now only outputs
# TODO numbering
# SELECTED STATE means TRANSITION ABOVE


import generator
import conversion
import copy
import random
import stateyasper
from collections import defaultdict


ar_file_input = defaultdict(list)
ar_file_output = defaultdict(list)
already_modified = []

# Entry point of applications
def perform_modifications(statemachine,amount=1,possible_modifications=[]):
    """Starting point for modifications upon interfaces.

    Performs modifications as specified in the peramaters. 
    N (amount) of modifications are selected at random from possible_modiifcations and then attempted
    to be applied upon the provided statemachine.

    

    Args:
        statemachine (generator.StateMachine object): An original statemachine object created using "generator.py"
        amount (int, optional): Amount of modifications to be applied upon interface. Defaults to 1.
        possible_modifications (list, optional): This should be a list of modification function references (from modifications.py). Defaults to [].

    Returns:
        (generator.StateMachine object,list): Returns a tuple containing the modified statemachine object 
                                              and the ordered list of modifications applied.
                                              This can be "False" if no modifications could succesfully be applied.
    """

    # Have to keep track of states already modified to prevent conflicts within AR file creation.
    global already_modified

    statemachine =  copy.deepcopy(statemachine)
    done_modifications = []

    
    # Loop over the amount of modifications to be selected.
    for _ in range(amount):

        # Select at random a modification from the function references list and store it
        selected = random.choice(possible_modifications)
        done_modifications.append(selected.__name__)

        # If the selected modification is create: 
        # The state upon which this may be applied cannot be a begin state.
        if selected == create:
            selected_state = random.choice([x for x in statemachine.states if x != statemachine.BeginState and x not in already_modified]) #)
            already_modified.append(selected_state)

            if not selected(statemachine,selected_state):
                print("Something went wrong") # Temporary debug
                return False
        
        # If the selected modification is delete or split, the selected transition must be an output on the server side.
        if selected == delete or selected == split:
            selected_state = random.choice([x.end for x in statemachine.transitions if x.output and x not in already_modified]) #)
            already_modified.append(selected_state)
            if not selected(statemachine,selected_state):
                print("Something went wrong") # Temporary debug
                return False

        # If the selected modification is merge the same rules apply as per delete and split, also have to select if merge must happen
        # on 2 or 3 outputs. 
        if selected == merge:
            selected_state = random.sample([x.end for x in statemachine.transitions if  x.output and x not in already_modified], random.choice([2,3])) #)
            already_modified.append(selected_state)

            if not merge(selected_state,statemachine):
                print("something went wrong")
                return False
                
       

    # TODO: UPDATE NUMBERS
   
    
    return (statemachine,done_modifications)


def create(statemachine,state,update_mapping_file=True):
    """Adapter creates a new signal to be sent
    from client to server.
    Which means the client needs to accept a signal that is not
    produced by the server. 
    Thus using mirrored client same as having a server
    that DOES send out a signal

    Args:
        statemachine ([type]): [description]
        state ([type]): [description]

    Returns:
        [type]: [description]
    """
    transition,_ = generator.r0(state,statemachine)
    generator.r0_1(transition,statemachine)

    # TODO 
    global ar_file_input
    global ar_file_output

    if update_mapping_file:
        # TODO multiple creates
        ar_file_output[""] = (transition.name)


    return transition # Succesfull always

def delete(statemachine,state,update_mapping_file=True):
    # TODO: have to make sure this doesnt make a start state
    # no longer a start state


    # Verify the leg choices
    if not generator.verify_leg_property(statemachine,state):
        print("Leg property debug")
        return False

    # All the transitions starting from this state (thus outgoing)
    transitions_start = [x for x in statemachine.transitions if x.start == state]
    # All transitions incoming
    transitions_end = [x for x in statemachine.transitions if x.end == state]
    

  



    # Mergin state will be the state BEFORE one deleted in same leg
    # Thus example: 1_4 delete becomes merging 1_3
    merging_state = None

    # Only way to have another incoming transition is through loop which is
    # result of non-determinism can't merge with that thus it will
    # be in another leg
    for x in transitions_end:
        # TODO: Changed not sure if works but assumption all legs lower are
        # result of a two way split from R2
        if x.start.leg <= state.leg:
            merging_state = x.start
            break

    if not merging_state:
        return False
    
    # Delete the transition connecting mergin state and deletion state
    # thus 1_3 -> 1_4 transition is top be deleted
    original_transition = None

    # All transitions ending at the delting state now need 
    # to end at the state being merged
    for x in transitions_end:
        if x.start == merging_state:
            original_transition = x
        else:
            x.end = merging_state

    for x in transitions_start:
        x.start = merging_state

    

    
    
    statemachine.transitions.remove(original_transition)
    statemachine.states.remove(state)

    merging_state.deterministic = state.deterministic
    merging_state.outgoing = state.outgoing
    merging_state.nondeterministic = state.nondeterministic

    # CHOICE PROPERTY primarily verify that when deleting for example
    # 1_3 the deletion doesn't occur on something that was previously
    # non-deterministic with different direction
    if not generator.verify_choice_property(statemachine):
        print("choice proeprty debug")
        return False

    # AR FILE FIXING:
    global ar_file_input
    global ar_file_output
    
    if update_mapping_file:
        if original_transition.input:
            del ar_file_input[original_transition.name]
            ar_file_input[""] = original_transition.name
        if original_transition.output:
            ar_file_output[original_transition.name] = ""

    
    return original_transition
    # TODO: UPDATE NUMBER here
    
    

def merge(states,statemachine):
   

    # States is a list of states either of length 2 or 3
    # have to verify they are all in the same leg
    check_leg = states[0].leg
    if not (states == [x for x in states if x.leg == check_leg]):
        return False

    # Now have deleted them
    deleted_transitions = []
    for state in states:
        temp = delete(statemachine,state,False)
       
        if not temp:
            return False
        deleted_transitions.append(temp.name)

    maximum_number = max(states,key = lambda x: x.number)
    possible_creations = [x for x in statemachine.states if x.leg == check_leg and x.number >= maximum_number.number]
    
    # No location possible for create
    if possible_creations == []:
        return False

    # Select a random position
    new_state_position = random.choice(possible_creations)

    # Create here
    created = create(statemachine,new_state_position,False)

    

    if not created:
        print('here')
        return False

  
    global ar_file_output


    for name in deleted_transitions:
        del ar_file_output[name]
     
    ar_file_output["S,tno_dynamics_out".join(deleted_transitions)] = created.name
    return True


def transform(states,statemachine):
    # States is a list of states either of length 2 or 3
    # have to verify they are all in the same leg
    check_leg = states[0].leg
    if not (states == [x for x in states if x.leg == check_leg]):
        return False

    # Now have deleted them
    for state in states:
        if not delete(statemachine,state):
            return False

    maximum_number = max(states,key = lambda x: x.number)
    possible_creations = [x for x in statemachine.states if x.leg == check_leg and x.number >= maximum_number]
    
    # No location possible for create
    if possible_creations == []:
        return False

    # Select a random position
    # TODO REDO NUMBERING
    first = create(statemachine, random.choice(possible_creations)) 
    second = create(statemachine, random.choice(possible_creations)) 
    # Create here
    return first and second


def split(statemachine,state):
    # States is a list of states either of length 2 or 3
    # have to verify they are all in the same leg
    check_leg = state.leg

    

    if not delete(statemachine,state,False):
        return False

  
    possible_creations = [x for x in statemachine.states if x.leg == check_leg and x.number >= state.number]
    
    # No location possible for create
    if possible_creations == []:
        return False

    # Select a random position
    # TODO REDO NUMBERING

    
    first = False
    second = False
    third = False
    # TODO ATTEMPTS VAR 
    for x in range(50):
        if first:
            break
        first = create(statemachine, random.choice(possible_creations))

    for x in range(50):
        if second:
            break
        second = create(statemachine, random.choice(possible_creations))

    for x in range(50):
        if third:
            break
        third = create(statemachine, random.choice(possible_creations))

    
    # Create here
    return first and second and third




def populate_ar_file(statemachine):
    global ar_file_input
    global ar_file_output
    
    for transition in statemachine.transitions:
        if transition.input:
            ar_file_input[transition.name] = transition.name
            # This will be C -> S
        else:
            ar_file_output[transition.name] = transition.name
            # This will be S -> C

 

# TODO: Remove unused
if __name__ == "__main__":

    # TODOOOO
# [150,222,602,1687,2452]:
# random.seed(5)
# wrong = 0
# for x in range(5090):
#     if x in [150,222,602,1687,2452]:
#         continue
#     random.seed(x)
#     print(x)
    INPUTS = 2
    OUTPUTS = 2
    NONDETERMINISM = 0.0
    statemachine_modified = False
    while not statemachine_modified:
        # rules = generator.random_generator(5,5,0.0)
        rules = generator.random_generator(INPUTS,OUTPUTS,0.0)
        statemachine  = generator.generate(rules)

        # populate it
        for transition in statemachine.transitions:
            if transition.input:
                ar_file_input[transition.name] = transition.name
                # This will be C -> S
            else:
                ar_file_output[transition.name] = transition.name
                # This will be S -> C



        statemachine_modified = perform_modifications(statemachine)
    # if statemachine_modified == False:
    #     wrong += 1


    # print(wrong)





    conversion.generate_conversion(statemachine,"V1")
    conversion.generate_conversion(statemachine_modified,"V2")

    with open('v1-original-server.pnml', 'w+') as f:
        print(stateyasper.generate_yasper(statemachine), file=f) 
    
    with open('v2-modified-server.pnml', 'w+') as f:
        print(stateyasper.generate_yasper(statemachine_modified), file=f) 

    # # TEMPORARY TODO
    from jinja2 import Environment, FileSystemLoader
    env = Environment(loader=FileSystemLoader('templates'))
    file_ar = env.get_template('ar.jinja').render(**locals())


    with open('test/{}.ar'.format("ZARFILE"), 'w+') as f:
        print(file_ar, file=f) 
    






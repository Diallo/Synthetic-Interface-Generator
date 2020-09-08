
import generator
import conversion
import copy
import random
import stateyasper
from collections import defaultdict

ar_file_input = defaultdict(list)
ar_file_output = defaultdict(list)


def perform_modifications(statemachine):


    statemachine =  copy.deepcopy(statemachine)

    # TODO: UPDATE NUMBERS
    # create(statemachine,statemachine.states[0])
    if delete(statemachine,statemachine.states[1]):
        return statemachine
    return None # Something went wrong during modification

def create(statemachine,state):
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

    ar_file_output[""].append(transition.name)


    # TODO: Create upon a non-determinsitic leg is not possible if it violates choice
    # TODO: random select
    # TODO: NAMING for transitions and places
    return True # Succesfull always

def delete(statemachine,state):
    # TODO: have to make sure this doesnt make a start state
    # no longer a start state


    # Verify the leg choices
    if not generator.verify_leg_property(statemachine,state):
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
        if x.start.leg == state.leg:
            merging_state = x.start
            break
    
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

    # AR FILE FIXING:
    global ar_file_input
    global ar_file_output

   
    if original_transition.input:
        del ar_file_input[original_transition.name]
        ar_file_input[""] = original_transition.name
    if original_transition.output:
        ar_file_output[original_transition.name] = None

    return generator.verify_choice_property(statemachine)
    # TODO: UPDATE NUMBER here
    
    

def merge(states,statemachine):
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
    possible_creations = [x for x in statemachine if x.leg == check_leg and x.number >= maximum_number]
    
    # No location possible for create
    if possible_creations == []:
        return False

    # Select a random position
    new_state_position = random.choice(possible_creations)

    # Create here
    return create(statemachine,new_state_position)


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
    possible_creations = [x for x in statemachine if x.leg == check_leg and x.number >= maximum_number]
    
    # No location possible for create
    if possible_creations == []:
        return False

    # Select a random position
    # TODO REDO NUMBERING
    first = create(statemachine, random.choice(possible_creations)) 
    second = create(statemachine, random.choice(possible_creations)) 
    # Create here
    return first and second


def split():
    # TODO: createa fucntion that renumbers the statemachine
    pass


random.seed(5)
rules = generator.random_generator(5,5,0.3)
statemachine  = generator.generate(rules)

# populate it
for transition in statemachine.transitions:
    if transition.input:
        ar_file_input[transition.name] = transition.name
        print(transition.name)
        # This will be C -> S
    else:
        ar_file_output[transition.name] = transition.name
        # This will be S -> C








statemachine_modified = perform_modifications(statemachine)


conversion.generate_conversion(statemachine,"V1")
conversion.generate_conversion(statemachine_modified,"V2")

# TEMPORARY TODO
from jinja2 import Environment, FileSystemLoader
env = Environment(loader=FileSystemLoader('templates'))
file_ar = env.get_template('ar.jinja').render(**locals())


with open('{}.ar'.format("ARFILE"), 'w+') as f:
    print(file_ar, file=f)  
   
    






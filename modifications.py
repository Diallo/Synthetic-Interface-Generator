import generator
import conversion
import copy
import random
import stateyasper

def perform_modifications(statemachine):
    statemachine =  copy.deepcopy(statemachine)


    # TODO: UPDATE NUMBERS
    # create(statemachine,statemachine.states[0])
    if delete(statemachine,statemachine.states[1]):
        return statemachine
    return None # Something went wrong during modification

def create(statemachine,state):
    # Create works upon a state
    # Create is simply like applying another r0
    transition,_ = generator.r0(state,statemachine)
    generator.r0_2(transition,statemachine)

    # TODO: Create upon a non-determinsitic leg is not possible if it violates choice
    # TODO: random select
    # TODO: NAMING for transitions and places
    return True # Succesfull always

def delete(statemachine,state):
    # TODO: have to make sure this doesnt make a start state
    # no longer a start state

    if not generator.verify_leg_property(statemachine,state):
        return False

    transitions_start = [x for x in statemachine.transitions if x.start == state]
    transitions_end = [x for x in statemachine.transitions if x.end == state]
    
    merging_state = None

    # Only way to have incoming transition is through loop which is
    # result of non-determinism can't merge with that thus it will
    # be in another leg
    for x in transitions_end:
        if x.start.leg == state.leg:
            merging_state = x.start
            break
    
    original_transition = None # transition for deletion
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
    return create(statemachine,state)



random.seed(5)
rules = generator.random_generator(5,5,0.3)
statemachine  = generator.generate(rules)
# print(statemachine.states[7]) # 1_3
# print(statemachine.states[1]) # 1_4


# print(generator.verify_leg_property(statemachine,statemachine.states[1]))

statemachine_modified = perform_modifications(statemachine)

# print(generator.verify_choice_property(statemachine_modified))
# print(generator.verify_leg_property(statemachine,statemachine.states[4]))
# print(statemachine)
# print(statemachine_modified)

# print(stateyasper.generate_yasper(statemachine))
# print(statemachine_modified)
print(stateyasper.generate_yasper(statemachine_modified))


# conversion.generate_conversion(statemachine,"V1")
# conversion.generate_conversion(statemachine_modified,"V2")



    






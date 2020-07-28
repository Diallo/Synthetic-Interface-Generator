import generator
import conversion
import copy
import random
import stateyasper


def perform_modifications(statemachine):
    statemachine =  copy.deepcopy(statemachine)

    create(statemachine,statemachine.states[0])
    return statemachine

def create(statemachine,state):
    # Create is simply like applying another r0
    transition,_ = generator.r0(state,statemachine)
    generator.r0_2(transition,statemachine)

    # TODO: Create upon a non-determinsitic leg is not possible if it violates choice
    # TODO: random select
    # TODO: NAMING for transitions and places






random.seed(5)
rules = generator.random_generator(5,5,0.3)
statemachine  = generator.generate(rules)
statemachine_modified = perform_modifications(statemachine)

print(generator.verify_choice_property(statemachine_modified))
print(generator.verify_leg_property(statemachine,statemachine.states[4]))

# print(statemachine_modified)

# print(stateyasper.generate_yasper(statemachine))
# print(stateyasper.generate_yasper(statemachine_modified))


# conversion.generate_conversion(statemachine,"V1")
# conversion.generate_conversion(statemachine_modified,"V2")



    






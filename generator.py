import random
import numpy as np
import math
import warnings
import argparse

from collections import defaultdict
from collections import Counter
import stateyasper
import conversion
import copy






# TODO: There might be a bug with incorrect number of transitions inputs/outputs?
class StateMachine:
   

    def __init__(self):
        self.rulelist = []
        self.transitions = []
        self.states = []
        self.BeginState = None
        self.FinalState = None
        self.legs = 1 # All portnets start with a single leg as the main leg
        


    def setBeginFinal(self):
        """This function determines which places in the portnet
        are to be marked begin/final after a refinement-iteration.
        """

        
        excludedBegin = set()   
        excludedFinal = set()

        # For a transition: Start -> End
        # Start/Final cannot be Final or Begin places respectively
        # so they're added to the set of excluded
        for t in self.transitions:
            excludedBegin.add(t.end)
            excludedFinal.add(t.start)
        
        # Find the states which are not present in the respective
        # excluded
        for state in self.states:
            if state not in excludedBegin:
                self.BeginState = state
            if state not in excludedFinal:
                self.FinalState = state
        # TODO: Test can be done here confirm the length of these sets is len(self.states) - 1
        
    


    # TODO: THIS NO LNOGER WORK BECAUSE .DETERMINISTIC IS GONE
    def __str__(self):
        output = "STATES: \n"
        for state in self.states:
            output += "\t state: {} ({})\n".format(state.name,"DT" if state.deterministic else "ND")
        output += "TRANSITIONS: \n"
        for transition in self.transitions:
            output += "\t transition: {} ({}) \n".format(transition,"input" if transition.input else "output")

        output += "Refinement Iterations: \n"
        for refinement_iteration in set(self.rulelist):

            output += "\t x{}: \t".format(self.rulelist.count(refinement_iteration))
            output += " --> ".join(map(lambda f:f.__name__, refinement_iteration))
  

            output += "\n"

        
        return output

class State:

    def __init__(self,name,statemachine,leg,number):
        self.name = name
        self.modifiable = True
        self.name = "p{}_{}".format(leg,number)
        # identifying info for leg STARTS AT 1
        self.leg = leg
        self.number = number

        # If this is lower than maximum of leg there was an expanison
        for state in statemachine.states:
            if state.leg == leg and state.number >= number:
                state.number += 1
                state.name = "p{}_{}".format(state.leg,state.number)
        statemachine.states.append(self)
        

    
           
    
    def __str__(self):
        return "state '{}'".format(self.name)

class Transition:

    count = 0

    def __init__(self,start,end,statemachine):
        self.name = "TR{}_{}".format(start.name,Transition.count)
        Transition.count += 1
        self.start = start
        self.end = end
        self.input = False # This indicates that this transition is an output
        self.output = False
        statemachine.transitions.append(self)
    
    def __str__(self):
        return "{} --> {}\n".format(self.start.name,self.end.name)


### Non modifiaction rules ### 
def r0(state,statemachine):
    """
    This rule expands a given state into two states with a transition between them. 
    """
    newState = State("r0_gen_{}".format(len(statemachine.states)),statemachine,state.leg,state.number + 1)

    # entire place is replacewd by new place -> transition -> place 
    for transition in statemachine.transitions:
        if transition.start == state:
            transition.start = newState

    transition = Transition(state,newState,statemachine)

  
    return (transition,None)

def r1(transition,statemachine):
    newState = State("r1_gen_{}".format(len(statemachine.states)),statemachine,transition.start.leg,transition.start.number + 1)
    newTransition = Transition(newState,transition.end,statemachine)
    transition.end = newState


    return (transition,newTransition) ### T1 and T2


def r2(transition,statemachine):
    newTransition = Transition(transition.start,transition.end,statemachine)
    
    
    # TODO: Don't need to do anything here about nondeterminism cause modified rules

    return (transition,newTransition) ### T1 and T2

def r3(state,statemachine):
    transition = Transition(state,state,statemachine)

    #TODO:L Dont need to do anything here about nondet cause modified rules

    return (state,transition)





### modifications of rules ###
    
def r0_1(transition,statemachine):
    transition.output = True
    return None,None
def r0_2(transition,statemachine):
    transition.input = True
    return None,None

def r1_1(t1,t2,statemachine):
    t1.input = True
    t2.output = True
    return None,None
def r1_2(t1,t2,statemachine):
    t1.output = True
    t2.input = True
    return None,None



def r2_1(t1,t2,statemachine):
    FirstLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine,statemachine.legs + 1,1)
    SecondLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine,statemachine.legs + 2,1)
    statemachine.legs += 2

    
    t3 = Transition(FirstLegState,t1.end,statemachine)
    t4 = Transition(SecondLegState,t1.end,statemachine)

    t1.end = FirstLegState
    t2.end = SecondLegState

    
    t1.output = True
    t2.output = True
    t3.input = True
    t4.input = True


   
    return None,None

    
def r2_2(t1,t2,statemachine):
    FirstLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine,statemachine.legs + 1,1)
    SecondLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine,statemachine.legs + 2,1)
    statemachine.legs += 2


    
    t3 = Transition(FirstLegState,t1.end,statemachine)
    t4 = Transition(SecondLegState,t1.end,statemachine)

    t1.end = FirstLegState
    t2.end = SecondLegState

    
    t3.output = True
    t4.output = True
    t1.input = True
    t2.input = True

    

    return None,None


def r3_1(p1,t1,statemachine):
    # In examples t1 is labeled as t2
    newState =  State("r3_gen_n{}".format(p1.name),statemachine,statemachine.legs + 1,1)
    statemachine.legs += 1
    t1.end = newState
    t2 = Transition(newState,p1,statemachine)

    t2.output = True
    t1.input = True


    
    return None,None

def r3_2(p1,t1,statemachine):
    
    # In examples t1 is labeled as t2
    newState =  State("r3_gen_n{}".format(p1.name),statemachine,statemachine.legs + 1,1)
    statemachine.legs += 1
    t1.end = newState
    t2 = Transition(newState,p1,statemachine)

    t2.input = True
    t1.output = True

    
   

    return None,None









def selected_rule_inputs_outputs(rule):
    # (inputs,outputs)
    if rule == r0_1:
        return (0,1)
    if rule == r0_2:
        return (1,0)
    if rule == r1_1 or rule == r1_2 or rule == r3_1 or rule == r3_2:
        return (1,1)
    if rule == r2_1 or rule == r2_2:
        return (2,2)
    else:
        return 0



def selected_rule_states(rule,placeDeterministic=False):
 
    # NOTE: r3 doesnt addd states but always followed by modified that does

    # Deterministic/Nondeterministic
    if rule == r0_1 or rule == r0_2 or rule == r1_1 or rule == r1_2:
        return 1,0
    if rule == r2_1 or rule == r2_2:
        return 2,2
    if rule == r3_1 or rule == r3_2:
        # It removes 1 deterministic rule and adds one
        
        return 0,2
    
    else:
        return 0,0


def verify_choice_property(statemachine):
    # TODO: THIS NO LONGER WORKS BECAUSE WE DO NOT HAVE NOTION OF X.DETERMINISTIC
    nondeterministic_states = [x for x in statemachine.states if x.deterministic == False]
    
    for state in nondeterministic_states:
        transitions = [x for x in statemachine.transitions if x.start == state]
        
        
        for transition in transitions:
            if transition.input != transitions[0].input:
                return False
    return True




def verify_leg_property(statemachine,deleting_state):
    """Verifies that a deletion of a state is legal based upon the leg property.

    Legs must have at least two transitions, which implies that within a leg
    there must be at least one transition. Generator guarantees such properties.
    Upon deletion of a transition, one state would disappear, thus to retain valid
    leg property there must be at least two states within a leg implying three 
    transitions.

    Args:
        statemachine (Statemachine): Current portnet representation.
        deleting_state (State): State that is to be deleted.

    Returns:
        Boolean: Would the deletion of this state invalidate portnet properties.
    """
    count = 0
    for state in statemachine.states:
        if state.leg == deleting_state.leg:
            count += 1


    return count >= 2 # Deleting legal
  

def max_prevalence(inputs,outputs):
    """Compute the maximum obtainable prevalence based upon
    an idealistic scenario in which only operations which increase 
    the prevalence of non-deterministence are selected.
    

    NOTE: 
        - Probabilistically unlikely to reach this.
        - Maximum values when inputs == outputs.

    Args:
        inputs (integer): Inputs for the simulated portnet.
        outputs (integer): Outputs for the simulated portnet.

    Returns:
        float: The maximum obtainable prevalence in a portnet with the given inputs/outputs.
    """
    r1 = abs(inputs-outputs)
    r2 = 1
    r3 = np.minimum(inputs,outputs) - (r2*2)
    deterministic = r1 + 2
    nondeterm = 2* (r2 + r3)
    prevalence = nondeterm/(deterministic+nondeterm)
    return prevalence

def random_generator(inputs,outputs,prevalence):
    """[summary]

    Arguments:
        inputs {[type]} -- [description]
        outputs {[type]} -- [description]
    """
    tempInputs = inputs
    tempOutputs = outputs
    
    
    
    nondeterministic = 0
    deterministic = 0
    currentPrevalence = 0


    
    Druleset = [(r0,r0_1), (r0,r0_2), (r0,r1,r1_1), (r0,r1,r1_1)]
    Nruleset = [(r3,r3_1),(r3,r3_2),(r0,r2,r2_1),(r0,r2,r2_2)]
    ruleset = None

    statemachine = StateMachine()
    state = State("start",statemachine,statemachine.legs,1)


    while tempInputs > 0 or tempOutputs > 0:
        statemachine.setBeginFinal()

        if currentPrevalence < prevalence and tempInputs >= 1 and tempOutputs >= 1 :
            
            #Nruleset
            ruleset = Nruleset
        else:
            ruleset = Druleset

        
        refinement_iteration = random.choice(ruleset)
        state = random.choice(statemachine.states)
        # Can't apply upon initial and final place
        
        while refinement_iteration[0] == r3 and (state == statemachine.BeginState or state == statemachine.FinalState):
            refinement_iteration = random.choice(ruleset)
            state = random.choice(statemachine.states)


           
        tempInputs -= selected_rule_inputs_outputs(refinement_iteration[-1])[0]
        tempOutputs -= selected_rule_inputs_outputs(refinement_iteration[-1])[1]

        if tempInputs < 0 or tempOutputs < 0:
            tempInputs += selected_rule_inputs_outputs(refinement_iteration[-1])[0]
            tempOutputs += selected_rule_inputs_outputs(refinement_iteration[-1])[1]
            continue



              

        firstParam = state
        secondParam = None

        for rule in refinement_iteration:
           

            # r3_1 or r3_2
            if rule == r3_1 or rule == r3_2:
            
                for transition in statemachine.transitions:
                    if transition.start == state:
                        if transition.input:
                            rule = r3_1
                        else:
                            rule = r3_2
                        break

                   
            if secondParam:
                firstParam, secondParam = rule(firstParam,secondParam,statemachine)
                
            else:
                firstParam, secondParam = rule(firstParam,statemachine)
        currentPrevalence = determine_non_determinism(statemachine)
        
       
   
    
   
    return statemachine


def determine_non_determinism(statemachine):
    deterministic = 0
    nondeterministic = 0

    transition_counts = defaultdict(int)

    for transition in statemachine.transitions:
        transition_counts[transition.start] += 1
    
   
    for state in statemachine.states:
       
        if transition_counts[state] > 1:
            nondeterministic += transition_counts[state]
        else:
            deterministic += transition_counts[state]



    
    return nondeterministic/(deterministic + nondeterministic)
        

   


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a PortNet / ComMA interface.')
    parser.add_argument('inputs', metavar='I', type=int, action='store',
                        help='Number of Inputs')
    parser.add_argument('outputs', metavar='O', type=int, action='store',
                    help='Number of Outputs')
    parser.add_argument('prevalence', metavar='P', type=float, action='store',
                    help='Prevalence of Non-Determinism')                   

    parser.add_argument('--f', dest='outputFile', action='store',
                        default="generation",
                        help='Enter Name of Output File')
    parser.add_argument('--g', dest='outputGraphical', action='store_false',
                        default=False,
                        help='Should a graphical reprsentation be given?')
    parser.add_argument('--s', dest='seed', action='store',
                     
                        help='random seed')

   
    args = parser.parse_args()

    ## Generate StateMachine
    # TODO: disable wrong parameter values
    if args.seed:
        random.seed(args.seed)

    inputs = args.inputs
    outputs = args.outputs
    prevalence = args.prevalence
    max_prev = max_prevalence(inputs,outputs)
    if prevalence > max_prev:
        warnings.warn("Prevalence of {} higher than maximum achievable {}".format(prevalence,max_prev), RuntimeWarning,stacklevel=2)
    
    statemachine = random_generator(inputs,outputs,prevalence)
    # print(verify_choice_property(statemachine))
    print(determine_non_determinism(statemachine))
    # statemachine  = generate(rules)

   


    with open('{}.pnml'.format(args.outputFile), 'w+') as f:
        print(stateyasper.generate_yasper(statemachine), file=f)  
    
    conversion.generate_conversion(statemachine,args.outputFile)




    

    
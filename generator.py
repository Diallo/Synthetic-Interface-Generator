import random
import numpy as np
import math
import warnings
import argparse

from collections import defaultdict
from collections import Counter
import stateyasper
import conversion
class StateMachine:
   

    def __init__(self):
        self.rulelist = []
        self.transitions = []
        self.states = []
        self.nondeterminsitics = 0
        self.deterministic = 0
        self.BeginState = None
        self.FinalState = None
        


    def setBeginFinal(self):
        BeginStates = self.states.copy()
        FinalStates = self.states.copy()
        excluded = set()
        for t in self.transitions:
            if t.end not in excluded:
                BeginStates.remove(t.end)
                excluded.add(t.end)
            if t.start not in excluded:
                FinalStates.remove(t.start)
                excluded.add(t.start)
        self.BeginState = BeginStates[0]
        self.FinalState = FinalStates[0]

    def __str__(self):
        output = "STATES: \n"
        for state in self.states:
            output += "\t state: {} \n".format(state.name)
        output += "TRANSITIONS: \n"
        for transition in self.transitions:
            output += "\t transition: {} \n".format(transition)

        output += "Refinement Iterations: \n"
        for refinement_iteration in set(self.rulelist):

            output += "\t x{}: \t".format(self.rulelist.count(refinement_iteration))
            output += " --> ".join(map(lambda f:f.__name__, refinement_iteration))
  

            output += "\n"

        
        return output

class State:

    def __init__(self,name,statemachine):
        self.name = name
        statemachine.states.append(self)
        self.deterministic = True
        self.outgoing = 0
       

    def __str__(self):
        return "state '{}'".format(self.name)

class Transition:

    def __init__(self,start,end,statemachine):
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
    newState = State("r0_gen_{}".format(len(statemachine.states)),statemachine)

    # entire place is replacewd by new place -> transition -> place 
    for transition in statemachine.transitions:
        if transition.start == state:
            transition.start = newState

    transition = Transition(state,newState,statemachine)

    return (transition,None)

def r1(transition,statemachine):
    newState = State("r1_gen_{}".format(len(statemachine.states)),statemachine)
    newTransition = Transition(newState,transition.end,statemachine)
    transition.end = newState

    return (transition,newTransition) ### T1 and T2


def r2(transition,statemachine):
    newTransition = Transition(transition.start,transition.end,statemachine)
    transition.start.deterministic = False
    return (transition,newTransition) ### T1 and T2

def r3(state,statemachine):
    transition = Transition(state,state,statemachine)
    return (state,transition)

def r4(transition,statemachine):
    pass



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
    FirstLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine)
    SecondLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine)

    
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
    FirstLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine)
    SecondLegState = State("r2_gen_{}".format(len(statemachine.states)),statemachine)

    
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
    newState =  State("r3_gen_n{}".format(p1.name),statemachine)
    t1.end = newState
    t2 = Transition(newState,p1,statemachine)

    t2.output = True
    t1.input = True

    return None,None

def r3_2(p1,t1,statemachine):
    # In examples t1 is labeled as t2
    newState =  State("r3_gen_n{}".format(len(statemachine.states)),statemachine)
    t1.end = newState
    t2 = Transition(newState,p1,statemachine)

    t2.input = True
    t1.output = True

    return None,None





Druleset = {}
Druleset["start"] = [r0]
Druleset[r0] = [r0_1,r0_2,r1]
Druleset[r1] = [r1_1,r1_2]

NRuleset = {}
NRuleset["start"] = [r0,r3]
NRuleset[r0] = [r2]

NRuleset[r2] = [r2_1,r2_2]
NRuleset[r3] = [r3_1,r3_2]
# ruleset[r4] = [] ]
# OTHER RULESETS TOO

################################################################################################
# TODO aadd r4





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
    if rule == r0_1 or rule == r0_2 or rule == r1_1 or rule == r1_2 or rule == r4 :
        return 1,0
    if rule == r2_1 or rule == r2_2:
        return 2,2
    if rule == r3_1 or rule == r3_2:
        # It removes 1 deterministic rule and adds one
        
        return 0,2
    
    else:
        return 0,0




def max_prevalence(inputs,outputs):
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
    
    # estimatedPlaces = round(inputs * 2 /AVGNUMBER)
    # rule2applications = round(prevalence * estimatedPlaces)
    ruleApplications = []


    
    nondeterministic = 0
    deterministic = 0
    currentPrevalence = 0

    while tempInputs > 0 or tempOutputs > 0:
        if currentPrevalence < prevalence and tempInputs >= 1 and tempOutputs >= 1 :
           
            currentState = "start"
            rules = []
            while currentState in NRuleset:
             
                madeChoice = random.choice(NRuleset[currentState])
                if madeChoice == r3 and deterministic == 0:
                    continue
                else:
                    currentState = madeChoice
                    rules.append(currentState)
                
            deterministic += selected_rule_states(currentState)[0]
            nondeterministic += selected_rule_states(currentState)[1]
            tempInputs -= selected_rule_inputs_outputs(currentState)[0]
            tempOutputs -= selected_rule_inputs_outputs(currentState)[1]

            if tempInputs < 0 or tempOutputs < 0:
                tempInputs += selected_rule_inputs_outputs(currentState)[0]
                tempOutputs += selected_rule_inputs_outputs(currentState)[1]
                deterministic += selected_rule_states(currentState)[0]
                nondeterministic += selected_rule_states(currentState)[1]
            else:
                ruleApplications.append(tuple(rules))


        
        # if prevalence above required
        else:
      
            currentState = "start"
            rules = []
            while currentState in Druleset:
             
                madeChoice = random.choice(Druleset[currentState])
                
                currentState = madeChoice
                rules.append(currentState)
                
            
            deterministic += selected_rule_states(currentState)[0]
            nondeterministic += selected_rule_states(currentState)[1]
            tempInputs -= selected_rule_inputs_outputs(currentState)[0]
            tempOutputs -= selected_rule_inputs_outputs(currentState)[1]

            if tempInputs < 0 or tempOutputs < 0:
                tempInputs += selected_rule_inputs_outputs(currentState)[0]
                tempOutputs += selected_rule_inputs_outputs(currentState)[1]
                deterministic += selected_rule_states(currentState)[0]
                nondeterministic += selected_rule_states(currentState)[1]
            else:
                ruleApplications.append(tuple(rules))

        currentPrevalence = nondeterministic/(nondeterministic+deterministic) 
      
       

    StateMachine.deterministic = deterministic
    StateMachine.nondeterminsitics = nondeterministic
    random.shuffle(ruleApplications)
   
   
    return ruleApplications


def determine_non_determinism(statemachine):
    deterministic = 0
    nondeterministic = 0

    for transition in statemachine.transitions:
        transition.start.outgoing += 1
    
   
    for state in statemachine.states:
       
        if state.outgoing > 1:
            nondeterministic += state.outgoing
        else:
            deterministic += state.outgoing
   
    return nondeterministic/(deterministic + nondeterministic)
        

    

def generate(rules):
    statemachine = StateMachine()
    statemachine.rulelist  = rules
    
    state = State("start",statemachine)
    rulesCopy = rules.copy()

    
    while len(rulesCopy) != 0:
        
        randomindex =  random.randrange(len(rulesCopy))
        ruleTuple = rulesCopy[randomindex]

        statemachine.setBeginFinal()

        state = random.choice(statemachine.states)
        while ruleTuple[0] == r3 and (state == statemachine.BeginState or state == statemachine.FinalState):
            state = random.choice(statemachine.states)
            randomindex =  random.randrange(len(rulesCopy))
            ruleTuple = rules[randomindex]

        firstParam = state
        secondParam = None
        for rule in ruleTuple:
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

        # TODO MAKE THIS POP PRESERVE order
        del rulesCopy[randomindex]
        

        
    return statemachine


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

    args = parser.parse_args()

    ## Generate StateMachine
    # TODO: disable wrong parameter values
    inputs = args.inputs
    outputs = args.outputs
    prevalence = args.prevalence
    max_prevalence = max_prevalence(inputs,outputs)
    if prevalence > max_prevalence:
        warnings.warn("Prevalence of {} higher than maximum achievable {}".format(prevalence,max_prevalence), RuntimeWarning,stacklevel=2)
    
    rules = random_generator(inputs,outputs,prevalence)
    statemachine  = generate(rules)

    conversion.generate_conversion(statemachine,args.outputFile)


    

    
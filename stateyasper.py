#!/usr/bin/python3

import generator
import sys

defaultS = " <place id='s{}'>\n       <name><text>{}</text> </name> <graphics>\n        <position x='{}' y='{}' />\n        <dimension x='20' y='20' />\n      </graphics>\n        </place>"

defaultT = "<transition id='s{}'> \n <graphics>\n <position x='330' y='{}' />\n <dimension x='32' y='32' />\n </graphics>\n </transition>"



def generate_yasper(statemachine):
    stateString  = "<?xml version='1.0' encoding='utf-8'?>\n"
    stateString +=  "<pnml>\n"
    stateString += "\t<net type='http://www.yasper.org/specs/epnml-1.1' id='do1'>\n"
    stateString += "\t<toolspecific tool='Yasper' version='1.2.4020.34351'>\n"
    stateString += "\t\t<roles xmlns='http://www.yasper.org/specs/epnml-1.1/toolspec' />\n"
    stateString += "\t</toolspecific>\n"
   
   
    transit, arcs = generate_transitions(statemachine.transitions)
    stateString += transit
    stateString += generate_places(statemachine.states)
    stateString += arcs

    return stateString + "\t</net> \n</pnml>"

def generate_places(states):
    x = 330
    y = 50
    output = ""

    
    for state in states:
        stateString = defaultS
        y += 100
        output += (stateString.format(state.name,state.name,x,y))
    return output

def generate_transitions(transitions):
    x = 330
    y = 70
    transitionNumber = 0
    output = ""
    arcs = ""

    for transition in transitions:
        y += 100
        transitionNumber += 1
       
        
        transitionString = defaultT
        stateInputString = defaultS

        # transitionName = "transition{}".format(transitionNumber)
        transitionName = "transition{}".format(transitionNumber)
        
        inputName = "{}{}".format("in" if transition.input else "out",transitionNumber)
        

        # This is the input
        output += stateInputString.format(inputName,inputName,x + 60,y)
        # trhis is the transiiton
        output += transitionString.format(transitionName,y)
    
        arcs += "<arc id='a{}' source='s{}' target='s{}' />\n".format("{}0".format(transitionNumber),transition.start.name,transitionName)
        arcs += "<arc id='a{}' source='s{}' target='s{}' />\n".format("{}5".format(transitionNumber),transitionName,transition.end.name)

        if transition.input:
            arcs += "<arc id='a{}' source='s{}' target='s{}' />\n".format("{}1".format(transitionNumber),inputName,transitionName)
        else:
            arcs += "<arc id='a{}' source='s{}' target='s{}' />\n".format("{}1".format(transitionNumber),transitionName,inputName)
            




    return output,arcs






if __name__ == "__main__":
    det = 0
    statemachine = None
    statemachine  = generator.generate(generator.random_generator(5,5,0.2))
    det = generator.determine_non_determinism(statemachine)
    # print(statemachine)
    print(generate_yasper(statemachine))


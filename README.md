# Abstract: 
There are many classes of Petri nets for describing communicating systems. Some of these guarantee important properties, such as
termination in the case of portnets. There are also many methods and
tools available for their analysis and synthesis. However, when developing new methods, or benchmarking against existing ones, it is often
helpful to quickly generate large sets of random models satisfying certain
properties and user-defined rules.
This paper presents a heuristic-driven method for synthetic generation of
random portnets based on refinement rules. The method considers three
user-specified complexity parameters: the expected number input and
output places, and the prevalence of non-determinism in the skeleton
of the generated net. An implementation of this method is available
as an open-source Python tool. Experiments demonstrate the relations
between the three complexity parameters and investigate the boundaries
of the proposed method.

# Description
This repository contains the source code for a PortNet (Petri Net) and CoMMa interface generator.
The code is a result of my bachelor thesis on "Towards the Scalability of Detecting and Correcting Incompatible Service Interfaces"







# Usage instructions
``Generation.py`` is the file responsible for the creation of interfaces. Invoke the file as ``python generation.py inputs outputs prevalence`` the required positional parameters inputs, outputs and prevalence of non-determinism are supplied. Optionally a file-name can be supplied using `--f filename` without any extension. If this is not done all output files with get the default name (and overwrite!) `generation`.  
  

``stateyasper`` file is used to generate code for [Yasper](http://www.yasper.org/) to display a graphical representation. As of right now there is no approach to neatly format this. 



# Additional Reading
Paper: https://diallom.com/static/pnse.pdf

Thesis: https://diallom.com/static/thesis.pdf
  
  
ComMA:  https://sws.cs.ru.nl/publications/papers/hooman/MODELSWARD2017.pdf

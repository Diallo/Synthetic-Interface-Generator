# Description
This repository contains the source code for a PortNet (Petri Net) and CoMMa interface generator.
The code is a result of my bachelor thesis on "Towards the Scalability of Detecting and Correcting Incompatible Service Interfaces"







# Usage instructions
``Generation.py`` is the file responsible for the creation of interfaces. Invoke the file as ``python generation.py inputs outputs prevalence`` the required positional parameters inputs, outputs and prevalence of non-determinism are supplied. Optionally a file-name can be supplied using `--f filename` without any extension. If this is not done all output files with get the default name (and overwrite!) `generation`.  
  

``stateyasper`` file is used to generate code for [Yasper](http://www.yasper.org/) to display a graphical representation. As of right now there is no approach to neatly format this. 



# Additional Reading
Thesis: https://diallom.com/static/thesis.pdf
  
  
ComMA:  https://sws.cs.ru.nl/publications/papers/hooman/MODELSWARD2017.pdf

# Abstract: 
In cyber-physical systems with long lifetimes, updating components is a costly process.
Service-oriented software architectures are used to introduce flexibility into a system. This
allows for modification of the underlying component, which implements a particular version
of an interface, causing the system to evolve. Service interfaces thus create an abstraction
layer over the components. With this abstraction layer, systems can be made up of various
components that may be replaced or modified, provided they implement the same version of
the interface. This abstraction breaks when service interfaces need to be modified, meaning
that all components implementing that interface may fail.
The Dynamics project proposes a methodology for detecting and correcting incompatibilities within service interfaces post-modification. The scalability of the methodology presented in Dynamics has not been evaluated. They do not have sufficient existing interfaces
to use for evaluations. This thesis aims to provide a starting point for the scalability evaluation of the proposed methodology. This will be done by generating synthetic interfaces of
various complexity. We make two contributions in this thesis. First, we define the notion
of complexity as inputs, outputs and non-determinism. Furthermore, the relation between
these parameters is studied. Second, the methodology for a ComMA interface generator
using user-supplied complexity parameters is introduced.

# Description
This repository contains the source code for a PortNet (Petri Net) and CoMMa interface generator.
The code is a result of my bachelor thesis on "Towards the Scalability of Detecting and Correcting Incompatible Service Interfaces"







# Usage instructions
``Generation.py`` is the file responsible for the creation of interfaces. Invoke the file as ``python generation.py inputs outputs prevalence`` the required positional parameters inputs, outputs and prevalence of non-determinism are supplied. Optionally a file-name can be supplied using `--f filename` without any extension. If this is not done all output files with get the default name (and overwrite!) `generation`.  
  

``stateyasper`` file is used to generate code for [Yasper](http://www.yasper.org/) to display a graphical representation. As of right now there is no approach to neatly format this. 



# Additional Reading
Thesis: https://diallom.com/static/thesis.pdf
  
  
ComMA:  https://sws.cs.ru.nl/publications/papers/hooman/MODELSWARD2017.pdf

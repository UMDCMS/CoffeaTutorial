###############################
Installing a coffea environment
###############################


Coffea is distributed as a python package that can be download by most machines.

Copy and paste commands
=======================

For those who are just looking for the basic script to help initialize the environment, here are the copy and paste commands:

LCG machines (``hepcms``, ``fnal``, ``lxplus``)
-----------------------------------------------

Make sure the machine is running **SL7**. For the installation:

.. code-block:: sh

  mkdir <WORKING_DIR>
  cd    <WORKING_DIR>
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/setup_LCG.sh
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/init.sh
  chmod +x setup_LCG.sh
  ./setup_LCG.sh

For starting the coffea session after fresh logging into a machine.

.. code-block:: sh

  cd <WORKING_DIR>
  source ./init_LCG.sh # Must be ran
  ./jupy.sh 8XXX       # Start a jupyter session, change XXX to your favorite 3-digit number

If you have want to use a remote jupyter session, make sure you have logged into
your machine using port forwarding

.. code-block:: sh

  ssh -L localhost:8XXX:localhost:8XXX <user>@<machine>

or equivalent. Make you should be able to open the notebook by going to your
browser and entering the URL ``localhost:8XXX``



Personal machines
-----------------

Make sure python version running is ``>3.6`` and  ``<3.9``, and the ``pip`` tool
in available. Optically install jupyter is you want to run coffea interactively
as a notebook.

.. code-block:: sh

  mkdir <WORKING_DIR>
  cd    <WORKING_DIR>
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/setup.sh
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/init.sh
  chmod +x setup.sh
  ./setup.sh

For starting a new session:

.. code-block:: sh

  cd <WORKINGDIR>
  source ./init.sh # Must be run to start virtual environment
   jupyter notebook --ip 0.0.0.0 --no-browser --notebook-dir .




Now for the more involved instructions on what there instructions are doing and
how you may want to modify the code for your own instructions.

Installing coffea the involved way
==================================


Installing the tutorial
=======================

Installing the entire tutorial as is is not advised for learning purposes, but
for the sake of people who will want to follow along notebook by notebook:


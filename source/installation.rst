###############################
Installing a coffea environment
###############################


Coffea is distributed as a python package that can be downloaded and installed by
any machine with python version > 3.6 and < 3.9. Notice that the various scripts
assumes that you have a simple bash shell. Using zsh will cause various commands
to fail.

Copy and paste commands
=======================

For those who are just looking for the basic script to help initialize the environment, here are the copy and paste commands:

LCG machines (``hepcms``, ``fnal``, ``lxplus``)
-----------------------------------------------

Make sure the machine is running **SL7**. For the installation (**warning** this
will probably take up to 10 minutes to complete):

.. code-block:: sh

  mkdir <WORKING_DIR>
  cd    <WORKING_DIR>
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/setup_LCG.sh
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/init.sh
  wget https://raw.githubusercontent.com/UMDCMS/CoffeaTutorial/main/jupy.sh
  chmod +x setup_LCG.sh
  chmod +x jupy.sh
  ./setup_LCG.sh

For starting the coffea session after fresh logging into a machine.

.. code-block:: sh

  cd <WORKING_DIR>
  source ./init.sh # Must be ran
  ./jupy.sh 8XXX   # Start a jupyter session,
                   # change XXX to your favorite 3-digit number

If you have want to use a remote jupyter session, make sure you have logged into
your machine using port forwarding

.. code-block:: sh

  ssh -L localhost:8XXX:localhost:8XXX <user>@<machine>

or equivalent. Make you should be able to open the notebook by going to your
browser and entering the URL ``localhost:8XXX``. When running the script
``./jupy.sh 8XXX``, you should see some string in the format of:

.. code-block:: sh

  http://127.0.0.1:8XXX/?token=02d4......


The entire string behind the ``token=`` part (should be something like 32
characters long) is the token used for logging into the notebook server.
Alternatively, you can paste the whole of the above into the borwser's url bar.


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

Installing and activating coffea the involved way
=================================================

The python virtual environment
------------------------------

Since coffea is a python package under very active development, it may require
additional dependencies and packages that may or may not conflict with the python
packages already installed by the system package manager. A python `virtual
environment <https://docs.python.org/3/library/venv.html>`_ creates a local
directory for store additional python packages independent of the system
directory, allowing for desired packages to be updated to be updated without
upsetting the system installation:

.. code-block:: sh

  cd <WORKINGDIR>
  python -m venv --copies coffeaenv

Next, activating the virtual environment resets the python environment variables,
so that it knows to install packages to our designated ``coffeaenv`` directory
instead of the system directory:

.. code-block:: sh

    source coffeaenv/bin/activate

Install coffea itself, this is done by the typical `pip` command

.. code-block:: sh

  python -m pip install --no-cache-dir setuptools pip --upgrade # updating
  python -m pip install --no-cache-dir coffea[dask]

The `--no-cache-dir` arguments ensures a fresh version of coffea is pulled from
pip servers, instead of looking for a system package called coffea.  The ``dask``
argument after coffea ensures that the ``dask`` part of coffea is installed.

Now the packages have been installed, you can start a python session with coffea
at any time using the

.. code-block:: sh

  source coffeaenv/bin/activate

command, and use

.. code-block:: sh

  deactivate

to return to the system python settings. One thing we are going to tweak that is
included in the ``init.sh`` script, is that by default, virtual environments
still prioritized looking for a package in the system package paths. This can
cause issues with mismatching package version in the system path and our virtual
environment. You can remedy this by setting the ``PYTHONPATH``  environment, so
that the package path within the virtual environment takes precedence. If you are
working with some custom package for analysis, you can also add your package path
now

.. code-block:: sh

  export PYTHONPATH=${VIRTUAL_ENV}/lib/python3/site-packages/:${PYTHONPATH}
  export PYTHONPATH=${PYTHONPATH}:<you/package/path>


For install on LCG machines, the steps are similar, except we can use additional
LCG tools to ensure that we have a correct python version:

.. code-block::sh

  source /cvmfs/sft.cern.ch/lcg/views/LCG_96python3/x86_64-centos7-gcc8-opt/setup.sh

You will need to source this file every time before the virtual environment is
activated, notice that there are a couples of lines in the ``setup_LCG.sh``
script to add the relevants lines to the ``coffeaenv/bin/activate`` script.



Requirements for setting up interactive notebooks
-------------------------------------------------

Notebooks are a handy tool for quick python snippet testing. Basically the
initialization of a notebook creates a consistent memory session where code
snippets can be rerun without having to start from the beginning of the notebook
itself. This is very handy for analysis, the on-going analysis steps might need
to be re-tested and adjusted multiple times before continuing.

Once activated, a notebook manager server can be initiated by the command:

.. code-block:: sh

  jupyter notebook --ip 0.0.0.0 --no-browser --notebook-dir .

The terminal should then output something like:

.. code-block:: sh

  http://127.0.0.1:8888/?token=c40c94b953f0f962cd26c4399d67417c9da2c92176178f21

Plugging this url into for favorite browser should great you with the directory
tree of the position of where you started the notebook server. Here you can
create and edit notebooks!

A couple of things is adjusted for remote machines. By default, notebook servers
save temporary files in the users home directory, which is typically a bad
practice for people logging onto grid machines. the ``init.sh`` script sets
additional environment variables to make sure storage uses the current directory,
which should be in the more flexible data directories:

.. code-block:: sh

  export JUPYTER_PATH=${PWD}}/.jupyter
  export JUPYTER_RUNTIME_DIR=${PWD}}/.local/share/jupyter/runtime
  export JUPYTER_DATA_DIR=${PWD}}/.local/share/jupyter
  export IPYTHONDIR=${PWD}/.ipython

Finally notice that the notebook server expects local traffic. To be able to
access the notebook of a remote machine, link to the machine with the command:

.. code-block:: sh

  ssh -L localhost:8XXX:localhost:8XXX  <user>@<machine>

which indicates that any network activity on port 8XXX should be passed over to
the remote machine on port 8XXX and vice versa. Now start the notebook server
with a specified port:

.. code-block:: sh

  jupyter notebook --ip 0.0.0.0 --no-browser --notebook-dir . --port 8XXX

And and you should be created with a similar url, execpt with the port fixed at
your given number.


A quick note on the phrase ``working directory``, in the context of notebooks. If
you are using the default browser interface to create notebooks, the ``working
directory`` will follow how you navigate in the directory structure: for example.
if you started the notebook in the ``/data`` directory and using the browser you
navigate to the `notebook/` directory to open an example `example.ipynb`
notebook. Your working directory will be `/data/notebook`. But if you are using
an external client to connect to the notebooks (ex using ``vscode
<https://code.visualstudio.com/docs/python/jupyter-support>``_ ), the working
directory will likely be fixed at ``/data``. This is something to keep in mind if
you are editing a custom package, and you get ``cannot find package`` errors when
running ``import mypackage``. With notebooks, you can always of the `os.getcwd`
method to make sure you are where you though you are.




Installing the tutorial
=======================

Installing the entire tutorial as is is not advised for learning purposes, but
for the sake of people who will want to follow along notebook by notebook:


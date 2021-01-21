Contributing to the tutorial repository
==========================================

This tutorial is hosted as a Github repository which can accessed `here
<https://github.com/UMDCMS/CoffeaTutorial>`_. Feels free to fork the directory to
contribute to the various topics found in this tutorial.

Here are a couple of guidelines for the submission of new content.

- Notebooks displayed in the tutorials should be **standalone**. The aim of
  this tutorial is to be a collection of code snippets that can be taken an
  modified independently by the learner, and not be an aggregation of functions
  and packages built on coffea. By doing so, we are ensuring that this tutorial
  remains a flexible tutorial, and not a dependency of any on-going analysis
  work. The only exception for providing a python package file is for coffea
  processing of the dummy data files described below.
- If you are demonstrating a certain data structure and how it can be
  manipulated, be sure to add such an example of how to generate such a
  structure, and an example generated root file in the ``samples`` directory.
  Please do **not** add any data file generated to be used for real research
  here. Example root files should be no larger than 50MB in size. Accompanying
  schema files should also be added to this directory if they exists.
- The contents of notebook should be cleaned and run exactly once from beginning
  to end. This ensures the cell indexes are rendered properly for the readers.
- Please do not arbitrarily edit the white-spaces found in files. This leads to
  pull requests that are tedious to read. This package includes an uncrustify_
  configuration file for C++ file parsing, and a yapf_ configuration file for
  python file parsing. Run your files through the code formatter before
  submitting a pull request.

The documentation webpage hosted by github would be automatically generated
whenever a change is made to the main branch. If you want to see the results of
the documentation locally before the results are pushed onto the main branch,
then you need to install the following packages:

- sphinx
- nbsphinx (requires pandoc)

The you should be able to generate the documentation by running the command

.. code-block:: sh

  make html

The resulting document will appear in ``build/html``.

.. _uncrustify : https://github.com/uncrustify/uncrustify
.. _yapf : https://github.com/google/yapf





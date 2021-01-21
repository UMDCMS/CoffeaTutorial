#!/bin/bash
echo "\nMaking and activiating the virtual environment ... "
python -m venv --copies coffeaenv
source coffeaenv/bin/activate

echo "\nInstalling 'pip' packages ... "
python -m pip install --no-cache-dir setuptools pip --upgrade
python -m pip install --no-cache-dir coffea


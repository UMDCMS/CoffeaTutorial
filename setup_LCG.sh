#!/bin/bash
NAME=coffeaenv
DEV=0

LCG=/cvmfs/sft.cern.ch/lcg/views/LCG_96python3/x86_64-centos7-gcc8-opt
source $LCG/setup.sh

# Install most of the needed software in a virtual environment following
# https://aarongorka.com/blog/portable-virtualenv/, an alternative is
# https://github.com/pantsbuild/pex

echo "\nMaking and activiating the virtual environment ... "
python3 -m venv --copies $NAME
source $NAME/bin/activate

echo "\nInstalling 'pip' packages ... "
python -m pip install --no-cache-dir setuptools pip --upgrade
python -m pip install --no-cache-dir coffea[dask]

# Setup the activation script for the virtual environment
echo "\nSetting up the activation script for the virtual environment ... "
sed -i '40s/.*/VIRTUAL_ENV="$(cd "$(dirname "$(dirname "${BASH_SOURCE[0]}" )")" \&\& pwd)"/' $NAME/bin/activate
find coffeaenv/bin/ -type f -print0 | xargs -0 -P 4 sed -i '1s/#!.*python$/#!\/usr\/bin\/env python/'
#sed -i "2a source ${LCG}/setup.sh" $NAME/bin/activate
#sed -i "4a source ${LCG}/setup.csh" $NAME/bin/activate.csh
deactivate
echo "\nFINISHED"

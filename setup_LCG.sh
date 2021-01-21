#!/bin/bash
NAME=coffeaenv
DEV=0

# Install most of the needed software in a virtual environment following
# https://aarongorka.com/blog/portable-virtualenv/, an alternative is
# https://github.com/pantsbuild/pex

echo "\nMaking and activiating the virtual environment ... "
python3 -m venv --copies $NAME
source $NAME/bin/activate

echo "\nInstalling 'pip' packages ... "
python -m pip install --no-cache-dir setuptools pip --upgrade
python -m pip install --no-cache-dir coffea

# Setup the activation script for the virtual environment
echo "\nSetting up the activation script for the virtual environment ... "
sed -i '40s/.*/VIRTUAL_ENV="$(cd "$(dirname "$(dirname "${BASH_SOURCE[0]}" )")" \&\& pwd)"/' $NAME/bin/activate
find coffeaenv/bin/ -type f -print0 | xargs -0 -P 4 sed -i '1s/#!.*python$/#!\/usr\/bin\/env python/'
#sed -i "2a source ${LCG}/setup.sh" $NAME/bin/activate
#sed -i "4a source ${LCG}/setup.csh" $NAME/bin/activate.csh

echo "\nSetting up the ipython/jupyter kernel ... "
storage_dir=$PWD
ipython kernel install --prefix=${storage_dir}/.local --name=$NAME
tar -zcf ${NAME}.tar.gz ${NAME}

deactivate
echo "\nFINISHED"

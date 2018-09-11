#!/bin/bash

################################################################################################################################################################

# @project        Library/Mathematics
# @file           tools/python/helpers/install.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        TBD

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pushd "${script_directory}" > /dev/null

pip install numpy --upgrade

popd > /dev/null

################################################################################################################################################################
#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd $DIR #move to script directory

sh remove_unsuitable_plugins.sh

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro
make -j4



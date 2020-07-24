#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd $DIR #move to script directory

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro
make -j4



#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

cd ../../src/pymeshlab
qmake pymeshlab.pro
make -j4



#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

cd ../../src
qmake PyMeshLab.pro
make -j4



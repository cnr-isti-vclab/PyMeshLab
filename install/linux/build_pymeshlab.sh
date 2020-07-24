#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro
make -j4



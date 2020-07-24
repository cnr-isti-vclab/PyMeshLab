#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro CONFIG+=debug
make -j4



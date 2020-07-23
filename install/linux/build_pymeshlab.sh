#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

bash remove_unsuitable_plugins.sh

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro
make -j4



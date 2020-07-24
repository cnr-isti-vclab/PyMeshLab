#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

bash remove_unsuitable_plugins.sh

bash update_plugins_paths.sh #todo: remove from here

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro CONFIG+=debug
make -j4



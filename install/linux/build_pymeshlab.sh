#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

bash remove_unsuitable_plugins.sh

bash update_plugins_paths.sh

cd ../../src/pymeshlabserver
qmake pymeshlabserver.pro
make -j4



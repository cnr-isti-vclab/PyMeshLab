#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

sudo apt-get install -y patchelf #todo remove

PLUGINS_DIR='../../pymeshlab/lib/meshlab/plugins'

patchelf --set-rpath '$ORIGIN/../..' $PLUGINS_DIR/*.so
patchelf --replace-needed libQt5Qml.so.5 ../../libQt5Qml.so.5 libfilter_sketchfab.so

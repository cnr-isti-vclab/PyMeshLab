#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

sudo apt-get install -y patchelf #todo remove

PLUGINS_DIR='../../pymeshlab/lib/meshlab/plugins'

patchelf --set-rpath '$ORIGIN/../..' $PLUGINS_DIR/*.so

ldd $PLUGINS_DIR/libfilter_sketchfab.so

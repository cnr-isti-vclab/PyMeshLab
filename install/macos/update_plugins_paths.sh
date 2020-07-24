#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd $DIR #move to script directory

PLUGINS_DIR='../../pymeshlab/lib/plugins'

for x in $PLUGINS_DIR/*.dylib
do
    install_name_tool -change @rpath/libmeshlab-common.1.dylib @loader_path/../Frameworks/libmeshlab-common.1.dylib $x
done

install_name_tool -change @rpath/libIFXCore.1.so @loader_path/../Frameworks/libIFXCore.1.so $PLUGINS_DIR/libio_u3d.dylib
install_name_tool -change @rpath/libIFXExporting.1.so @loader_path/../Frameworks/libIFXExporting.1.so $PLUGINS_DIR/libio_u3d.dylib
install_name_tool -change @rpath/libIFXScheduling.1.so @loader_path/../Frameworks/libIFXScheduling.1.so $PLUGINS_DIR/libio_u3d.dylib

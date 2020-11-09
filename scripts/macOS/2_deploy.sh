#!/bin/bash

#realpath function
realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

SCRIPTS_PATH=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

#checking for parameters
if [ "$#" -eq 0 ]
then
    BUNDLE_PATH=$SCRIPTS_PATH/../../pymeshlab
else
    BUNDLE_PATH=$(realpath $1)
fi

MODULE_NAME=$(find $BUNDLE_PATH/dummybin.app/Contents  -name 'pmeshlab*')

install_name_tool -change @rpath/libmeshlab-common.dylib @executable_path/../Frameworks/libmeshlab-common.dylib $BUNDLE_PATH/dummybin.app/Contents/MacOS/dummybin

install_name_tool -add_rpath @loader_path/Frameworks $MODULE_NAME
#install_name_tool -change @rpath/libmeshlab-common.dylib @loader_path/Frameworks/libmeshlab-common.dylib pymeshlab/pmeshlab*
#install_name_tool -change @rpath/libmeshlab-common.dylib Frameworks/libmeshlab-common.dylib $BUNDLE_PATH/dummybin.app/Contents/pmeshlab*

if [ -e $QTDIR/bin/macdeployqt ]
then
    $QTDIR/bin/macdeployqt $BUNDLE_PATH/dummybin.app -executable=$MODULE_NAME -executable=$BUNDLE_PATH/dummybin.app/Contents/PlugIns/libfilter_sketchfab.so
else
        macdeployqt $BUNDLE_PATH/dummybin.app -executable=$MODULE_NAME -executable=$BUNDLE_PATH/dummybin.app/Contents/PlugIns/libfilter_sketchfab.so
fi

rsync -a $BUNDLE_PATH/dummybin.app/Contents/Frameworks/ $BUNDLE_PATH/Frameworks/
rsync -a $BUNDLE_PATH/dummybin.app/Contents/PlugIns/ $BUNDLE_PATH/PlugIns/
mv $BUNDLE_PATH/dummybin.app/Contents/pmeshlab* $BUNDLE_PATH/
rm -rf $BUNDLE_PATH/dummybin.app


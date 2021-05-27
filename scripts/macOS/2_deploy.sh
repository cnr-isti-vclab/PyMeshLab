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

if [ -e $QTDIR/bin/macdeployqt ]
then
    MACDEPLOYQT_EXE=$QTDIR/bin/macdeployqt
else
    MACDEPLOYQT_EXE=macdeployqt
fi

${MACDEPLOYQT_EXE} $BUNDLE_PATH/dummybin.app \
    -executable=$MODULE_NAME \
    -executable=$BUNDLE_PATH/dummybin.app/Contents/PlugIns/libfilter_isoparametrization.so \
    -executable=$BUNDLE_PATH/dummybin.app/Contents/PlugIns/libfilter_mesh_booleans.so \
    -executable=$BUNDLE_PATH/dummybin.app/Contents/PlugIns/libfilter_screened_poisson.so \
    -executable=$BUNDLE_PATH/dummybin.app/Contents/PlugIns/libfilter_sketchfab.so

rsync -a $BUNDLE_PATH/dummybin.app/Contents/Frameworks/ $BUNDLE_PATH/Frameworks/
rsync -a $BUNDLE_PATH/dummybin.app/Contents/PlugIns/ $BUNDLE_PATH/PlugIns/
mv $BUNDLE_PATH/dummybin.app/Contents/pmeshlab* $BUNDLE_PATH/
rm -rf $BUNDLE_PATH/dummybin.app

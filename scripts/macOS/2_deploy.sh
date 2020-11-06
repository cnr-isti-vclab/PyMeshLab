#!/bin/bash
# This is a script shell for deploying a pymeshlab-portable folder.
# Requires a properly built PyMeshLab (see 1_build.sh).
#
# This script can be run only in the oldest supported linux distro
# due to linuxdeployqt tool choice (see https://github.com/probonopd/linuxdeployqt/issues/340).
#
# Without given arguments, the folder that will be deployed is pymeshlab, which
# should be the path where PyMeshLab has been installed (default output of 1_build.sh).
#
# You can give as argument the path where you installed PyMeshLab.

SCRIPTS_PATH=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

#checking for parameters
if [ "$#" -eq 0 ]
then
    BUNDLE_PATH=$SCRIPTS_PATH/../../pymeshlab
else
    BUNDLE_PATH=$(realpath $1)
fi

install_name_tool -change @rpath/libmeshlab-common.dylib Frameworks/libmeshlab-common.dylib $BUNDLE_PATH/dummybin.app/Contents/pmeshlab*

if [ -e $QTDIR/bin/macdeployqt ]
then
    $QTDIR/bin/macdeployqt $BUNDLE_PATH/dummybin.app -executable=$INSTALL_PATH/$BUNDLE_PATH/dummybin.app/pmeshlab*
else
        macdeployqt $BUNDLE_PATH/dummybin.app -executable=$INSTALL_PATH/$BUNDLE_PATH/dummybin.app/pmeshlab*
fi

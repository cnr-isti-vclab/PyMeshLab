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

SCRIPTS_PATH="$(dirname "$(realpath "$0")")"

#checking for parameters
if [ "$#" -eq 0 ]
then
    BUNDLE_PATH=$SCRIPTS_PATH/../../pymeshlab
else
    BUNDLE_PATH=$(realpath $1)
fi

windeployqt $BUNDLE_PATH/pmeshlab*
windeployqt $BUNDLE_PATH/lib/plugins/filter_sketchfab.dll --libdir $BUNDLE_PATH

rm $BUNDLE_PATH/d3dcompiler*
if ls $BUNDLE_PATH/vc_redist* 1> /dev/null 2>&1; then
    rm $BUNDLE_PATH/vc_redist*
fi

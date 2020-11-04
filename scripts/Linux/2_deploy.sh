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
LINUXDEPLOYQT_PATH=$SCRIPTS_PATH/../../src/meshlab/scripts/Linux/resources

#checking for parameters
if [ "$#" -eq 0 ]
then
    BUNDLE_PATH=$SCRIPTS_PATH/../../src/build/distrib/pymeshlab
else
    BUNDLE_PATH=$(realpath $1)
fi

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$BUNDLE_PATH/lib

$LINUXDEPLOYQT_PATH/linuxdeployqt $BUNDLE_PATH/pmeshlab* \
  -bundle-non-qt-libs \
  -executable=$BUNDLE_PATH/lib/libmeshlab-common.so \
  -executable=$BUNDLE_PATH/lib/plugins/libfilter_sketchfab.so \
  -executable=$BUNDLE_PATH/lib/plugins/libio_3ds.so \
  -executable=$BUNDLE_PATH/lib/plugins/libio_ctm.so

rm $BUNDLE_PATH/AppRun
if [ -d "$BUNDLE_PATH/doc" ]
then
    rm -r $BUNDLE_PATH/doc
fi

#!/bin/bash
# This is a script shell for deploying a pymeshlab-portable folder.
# Requires a properly built PyMeshLab (see 1_build.sh).
#
# Without given arguments, the folder that will be deployed is pymeshlab, which
# should be the path where PyMeshLab has been installed (default output of 1_build.sh).
#
# You can give as argument the path where you installed PyMeshLab.

SCRIPTS_PATH="$(dirname "$(realpath "$0")")"
LINUXDEPLOY_PATH=$SCRIPTS_PATH/../../src/meshlab/scripts/Linux/resources
QT_DIR=""
BUNDLE_PATH=$SCRIPTS_PATH/../../pymeshlab

#checking for parameters
for i in "$@"
do
case $i in
    -i=*|--install_path=*)
        BUNDLE_PATH="${i#*=}"
        shift # past argument=value
        ;;
    -qt=*|--qt_dir=*)
        QT_DIR=${i#*=}
        shift # past argument=value
        ;;
    *)
        # unknown option
        ;;
esac
done

if [ ! -z "$QT_DIR" ]
then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QT_DIR/lib
    export QMAKE=$QT_DIR/bin/qmake
fi

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$BUNDLE_PATH/usr/lib

mkdir $BUNDLE_PATH/usr
mv $BUNDLE_PATH/lib $BUNDLE_PATH/usr/lib

PMESHLAB_MODULE_PATH=$(ls -d $BUNDLE_PATH/pmeshlab*)
$LINUXDEPLOY_PATH/linuxdeploy --executable=$PMESHLAB_MODULE_PATH \
  --appdir=$BUNDLE_PATH \
  --plugin qt

rsync -av $BUNDLE_PATH/usr/lib $BUNDLE_PATH/

rm -rf $BUNDLE_PATH/usr/
rm -rf $BUNDLE_PATH/apprun-hooks/

patchelf --set-rpath '$ORIGIN/lib/' $PMESHLAB_MODULE_PATH

#for plugin in $BUNDLE_PATH/lib/plugins/*.so
#do
#    patchelf --set-rpath '$ORIGIN/../' $plugin
#done

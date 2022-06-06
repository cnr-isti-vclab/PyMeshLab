#!/bin/bash
# This is a script shell for deploying a pymeshlab-portable folder.
# Requires a properly built PyMeshLab (see 1_build.sh).
#
# Without given arguments, the folder that will be deployed is pymeshlab, which
# should be the path where PyMeshLab has been installed (default output of 1_build.sh).
#
# You can give as argument the path where you installed PyMeshLab.

SCRIPTS_PATH="$(dirname "$(realpath "$0")")"
LINUXDEPLOY_PATH=$SCRIPTS_PATH/../../src/meshlab/resources/linux
QT_DIR=""
INSTALL_PATH=$SCRIPTS_PATH/../../pymeshlab

#checking for parameters
for i in "$@"
do
case $i in
    -i=*|--install_path=*)
        INSTALL_PATH="${i#*=}"
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

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_PATH/usr/lib

mkdir $INSTALL_PATH/usr
mv $INSTALL_PATH/lib $INSTALL_PATH/usr/lib

PMESHLAB_MODULE_PATH=$(ls -d $INSTALL_PATH/pmeshlab*)
$LINUXDEPLOY_PATH/linuxdeploy --executable=$PMESHLAB_MODULE_PATH \
  --appdir=$INSTALL_PATH \
  --plugin qt

rsync -av $INSTALL_PATH/usr/lib $INSTALL_PATH/

rm -rf $INSTALL_PATH/usr/
rm -rf $INSTALL_PATH/apprun-hooks/

patchelf --set-rpath '$ORIGIN/lib/' $PMESHLAB_MODULE_PATH

for plugin in $INSTALL_PATH/lib/plugins/*.so
do
    patchelf --set-rpath '$ORIGIN/../' $plugin
done

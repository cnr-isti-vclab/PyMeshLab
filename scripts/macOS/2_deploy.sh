#!/bin/bash

SCRIPTS_PATH=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

INSTALL_PATH=$SCRIPTS_PATH/../../pymeshlab
QT_DIR=""

#checking for parameters
for i in "$@"
do
case $i in
    -i=*|--install_path=*)
        INSTALL_PATH="${i#*=}"
        shift # past argument=value
        ;;
    -qt=*|--qt_dir=*)
        QT_DIR=${i#*=}/bin/
        shift # past argument=value
        ;;
    *)
        # unknown option
        ;;
esac
done

MODULE_NAME=$(find $INSTALL_PATH/dummybin.app/Contents  -name 'pmeshlab*')

${QT_DIR}macdeployqt $INSTALL_PATH/dummybin.app \
    -executable=$MODULE_NAME \
    -executable=$INSTALL_PATH/dummybin.app/Contents/PlugIns/libfilter_isoparametrization.so \
    -executable=$INSTALL_PATH/dummybin.app/Contents/PlugIns/libfilter_mesh_booleans.so \
    -executable=$INSTALL_PATH/dummybin.app/Contents/PlugIns/libfilter_screened_poisson.so \
    -executable=$INSTALL_PATH/dummybin.app/Contents/PlugIns/libfilter_sketchfab.so \
    -executable=$INSTALL_PATH/dummybin.app/Contents/PlugIns/libio_e57.so

rsync -a $INSTALL_PATH/dummybin.app/Contents/Frameworks/ $INSTALL_PATH/Frameworks/
rsync -a $INSTALL_PATH/dummybin.app/Contents/PlugIns/ $INSTALL_PATH/PlugIns/
mv $INSTALL_PATH/dummybin.app/Contents/pmeshlab* $INSTALL_PATH/
rm -rf $INSTALL_PATH/dummybin.app

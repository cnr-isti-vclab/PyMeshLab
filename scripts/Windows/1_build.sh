#!/bin/bash

SCRIPTS_PATH="$(dirname "$(realpath "$0")")"
SOURCE_PATH=$SCRIPTS_PATH/../../src
BUILD_PATH=$SOURCE_PATH/../build
INSTALL_PATH=$SOURCE_PATH/../pymeshlab
BUILD_MESHLAB_OPTION=""
BUILD_OPTION="-DCMAKE_BUILD_TYPE=Release"
NIGHTLY_OPTION=""
QT_DIR=""

#check parameters
for i in "$@"
do
case $i in
    -b=*|--build_path=*)
        BUILD_PATH="${i#*=}"
        shift # past argument=value
        ;;
    -i=*|--install_path=*)
        INSTALL_PATH="${i#*=}"
        shift # past argument=value
        ;;
    --no-build-meshlab)
        BUILD_MESHLAB_OPTION="-DBUILD_MESHLAB=OFF"
        shift # past argument=value
        ;;
    --debug)
        BUILD_OPTION="-DCMAKE_BUILD_TYPE=Debug"
        shift # past argument=value
        ;;
    -n|--nightly)
        NIGHTLY_OPTION="-DMESHLAB_IS_NIGHTLY_VERSION=ON"
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

#create build path if necessary
if ! [ -d $BUILD_PATH ]
then
    mkdir -p $BUILD_PATH
fi

#create install path if necessary
if ! [ -d $INSTALL_PATH ]
then
    mkdir -p $INSTALL_PATH
fi

BUILD_PATH=$(realpath $BUILD_PATH)
INSTALL_PATH=$(realpath $INSTALL_PATH)

cd $BUILD_PATH
if [ ! -z "$QT_DIR" ]
then
    export Qt5_DIR=$QT_DIR
fi

cmake -GNinja $BUILD_OPTION -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH $BUILD_MESHLAB_OPTION $NIGHTLY_OPTION $SOURCE_PATH
ninja
ninja install

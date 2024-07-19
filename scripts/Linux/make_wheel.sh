#!/bin/bash

SCRIPTS_PATH="$(dirname "$(realpath "$0")")"
SOURCE_PATH=$SCRIPTS_PATH/../..

BUILD_PATH=$SOURCE_PATH/build
BUILD_OPTION=""

INSTALL_PATH=$SOURCE_PATH/pymeshlab
INSTALL_OPTION=""

WHEELS_PATH=$SOURCE_PATH/wheels

NIGHTLY_OPTION=""
QT_OPTION=""
CCACHE_OPTION=""

#check parameters
for i in "$@"
do
case $i in
    -b=*|--build_path=*)
        BUILD_PATH="${i#*=}"
        BUILD_OPTION="-b=${i#*=}"
        shift # past argument=value
        ;;
    -i=*|--install_path=*)
        INSTALL_PATH="${i#*=}"
        INSTALL_OPTION="-i=${i#*=}"
        shift # past argument=value
        ;;
    -w=*|--wheels_path=*)
        WHEELS_PATH="${i#*=}"
        shift # past argument=value
        ;;
    -n|--nightly)
        NIGHTLY_OPTION="-n"
        shift # past argument=value
        ;;
    -qt=*|--qt_dir=*)
        QT_OPTION="-qt=${i#*=}"
        shift # past argument=value
        ;;
    --ccache)
        CCACHE_OPTION="--ccache"
        shift # past argument=value
        ;;
    *)
        # unknown option
    ;;
esac
done

bash $SCRIPTS_PATH/1_build.sh $BUILD_OPTION $INSTALL_OPTION $NIGHTLY_OPTION $QT_OPTION $CCACHE_OPTION
bash $SCRIPTS_PATH/2_deploy.sh $INSTALL_OPTION $QT_OPTION

pip wheel $SOURCE_PATH -w $WHEELS_PATH

rm -rf $BUILD_PATH
rm -rf $INSTALL_PATH/pmeshlab*
rm -rf $INSTALL_PATH/lib
rm -rf pymeshlab.egg-info
#!/bin/bash

#realpath function
realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd $DIR #move to script directory

DISTRIB_PATH=$(realpath ../../PyMeshLab)

BUILD_PATH=$(realpath ../../build)

mkdir $BUILD_PATH

bash ../../meshlab/install/macos/macos_build.sh $BUILD_PATH

#rm -r $DISTRIB_PATH/*

cp -a $BUILD_PATH/distrib/lib $DISTRIB_PATH/
cp -a $BUILD_PATH/distrib/plugins $DISTRIB_PATH/

#rm -r $BUILD_PATH

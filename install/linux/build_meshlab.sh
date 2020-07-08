#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

DISTRIB_PATH=$(realpath ../../PyMeshLab)

BUILD_PATH=$(realpath ../../build)

mkdir $BUILD_PATH

bash ../../meshlab/install/linux/linux_build.sh $BUILD_PATH

#rm -r $DISTRIB_PATH/*

cp -ar $BUILD_PATH/distrib/lib $DISTRIB_PATH/
cp -ar $BUILD_PATH/distrib/plugins $DISTRIB_PATH/

rm -r $BUILD_PATH

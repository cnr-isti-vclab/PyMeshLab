#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

DISTRIB_PATH=$(realpath ../../pymeshlab)

BUILD_PATH=$(realpath ../../build)

mkdir $BUILD_PATH

bash ../../meshlab/install/linux/linux_build.sh $BUILD_PATH
bash ../../meshlab/install/linux/linux_make_boundle.sh $BUILD_PATH/distrib
bash ../../meshlab/install/linux/linux_deploy.sh $BUILD_PATH/distrib

cp -ar $BUILD_PATH/distrib/usr/lib $DISTRIB_PATH/

rm -r $BUILD_PATH

bash remove_unsuitable_plugins.sh
bash update_plugins_paths.sh

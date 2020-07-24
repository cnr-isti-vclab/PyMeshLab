#!/bin/bash

#realpath function
realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd $DIR #move to script directory

DISTRIB_PATH=$(realpath ../../pymeshlab)

BUILD_PATH=$(realpath ../../build)

mkdir $BUILD_PATH

bash ../../meshlab/install/macos/macos_build.sh $BUILD_PATH
bash ../../meshlab/install/macos/macos_deploy.sh $BUILD_PATH/distrib

cd $BUILD_PATH/distrib
rm -r lib
rm -r plugins
rm -r shaders
rm LICENSE.txt
rm meshlab.png
rm privacy.txt
rm readme.txt
rm README.md
mkdir -p lib/plugins
cp -R meshlab.app/Contents/Frameworks lib/
mv lib/Frameworks/libmeshlab-common* lib/
cp -R meshlab.app/Contents/PlugIns/* lib/plugins/
cp -R lib $DISTRIB_PATH/

rm -r $BUILD_PATH

cd $DIR

sh remove_unsuitable_plugins.sh 
sh update_plugins_paths.sh

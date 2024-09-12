#!/bin/bash

SCRIPTS_PATH=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/..

INSTALL_PATH=$SCRIPTS_PATH/../../pymeshlab
QT_DIR=""
MAC_M1=false

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
    --mac_m1)
        MAC_M1=true
        shift # past argument=value
        ;;
    *)
        # unknown option
        ;;
esac
done

MODULE_NAME=$(find $INSTALL_PATH/dummybin.app/Contents  -name 'pmeshlab*')

ARGUMENTS=""

for plugin in $INSTALL_PATH/dummybin.app/Contents/PlugIns/*.so
do
    ARGUMENTS="${ARGUMENTS} -executable=${plugin}"
done

if [ ! -z "$QT_DIR" ]
then
    export Qt5_DIR=$QT_DIR
fi

# save in message the output of macdeployqt
message=$(${QT_DIR}macdeployqt $INSTALL_PATH/dummybin.app \
    -executable=$MODULE_NAME \
    $ARGUMENTS 2>&1)

# if message contains "ERROR" then macdeployqt failed
if [[ $message == *"ERROR"* ]]; then
    echo "macdeployqt failed."
    echo "macdeployqt output:"
    echo $message
    exit 1
fi

echo "macdeployqt completed successfully."
rsync -a $INSTALL_PATH/dummybin.app/Contents/Frameworks/ $INSTALL_PATH/Frameworks/
rsync -a $INSTALL_PATH/dummybin.app/Contents/PlugIns/ $INSTALL_PATH/PlugIns/
mv $INSTALL_PATH/dummybin.app/Contents/pmeshlab* $INSTALL_PATH/
rm -rf $INSTALL_PATH/dummybin.app

# save current dir
current_dir=$(pwd)

cd $INSTALL_PATH/PlugIns

# for libio_3mf.so, we need to change '@rpath/lib3mf.2.dylib' to '@loader_path/../Frameworks/lib3mf.2.dylib'
# TODO: try to understand why this is needed (only for arm64, and only in pymeshlab... the meshlab app works fine without this)
install_name_tool -change @rpath/lib3mf.2.dylib @loader_path/../Frameworks/lib3mf.2.dylib libio_3mf.so

if [ "$MAC_M1" = true ] ; then
    cd $INSTALL_PATH/Frameworks

    # for each directory called Qt*.framework
    for dir in Qt*.framework
    do
        rm -rf $dir/Versions/Current
        cp -r $dir/Versions/5 $dir/Versions/Current
    done
fi

cd $current_dir

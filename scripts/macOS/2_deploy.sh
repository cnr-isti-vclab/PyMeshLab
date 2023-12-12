#!/bin/bash

SCRIPTS_PATH=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

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

if [ "$MAC_M1" = true ] ; then
    cd $INSTALL_PATH/Frameworks

    # for each directory called Qt*.framework
    for dir in Qt*.framework
    do
        # in $dir/Versions move the directory called Current in a new directory called 5
        mv $dir/Versions/Current $dir/Versions/5
        # make a symbolic link called Current to the directory called 5
        cd $dir/Versions
        ln -s 5 Current
        cd ../..
    done
fi


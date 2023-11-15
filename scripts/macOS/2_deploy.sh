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

ARGUMENTS=""

for plugin in $INSTALL_PATH/dummybin.app/Contents/PlugIns/*.so
do
    ARGUMENTS="${ARGUMENTS} -executable=${plugin}"
done

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




#!/bin/bash

SCRIPTS_PATH=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/..

INSTALL_PATH=$SCRIPTS_PATH/../../pymeshlab
CERT_ID=""

#checking for parameters
for i in "$@"
do
case $i in
    -i=*|--install_path=*)
        INSTALL_PATH="${i#*=}"
        shift # past argument=value
        ;;
    -ci=*|--cert_id=*)
        CERT_ID="${i#*=}"
        shift # past argument=value
        ;;
    *)
        # unknown option
        ;;
esac
done

codesign --options "runtime" --timestamp --force --deep --sign $CERT_ID $INSTALL_PATH/*.so
codesign --options "runtime" --timestamp --force --deep --sign $CERT_ID $INSTALL_PATH/Frameworks/*.dylib
codesign --options "runtime" --timestamp --force --deep --sign $CERT_ID $INSTALL_PATH/PlugIns/*.so
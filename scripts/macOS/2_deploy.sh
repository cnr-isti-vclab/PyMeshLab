#!/bin/bash

SCRIPTS_PATH="$(dirname "$(realpath "$0")")"

INSTALL_PATH=$SCRIPTS_PATH/../../pymeshlab
QT_DIR_OPTION=""
SIGN=false
CERT_ID=""
MAC_M1_OPTION=""

#checking for parameters
for i in "$@"
do
case $i in
    -i=*|--install_path=*)
        INSTALL_PATH="${i#*=}"
        shift # past argument=value
        ;;
    -qt=*|--qt_dir=*)
        QT_DIR_OPTION=-qt=${i#*=}
        shift # past argument=value
        ;;
    --use_brew_qt)
        QT_DIR_OPTION=-qt=$(brew --prefix qt5)
        shift # past argument=value
        ;;
    --mac_m1)
        MAC_M1_OPTION=--mac_m1
        shift # past argument=value
        ;;
    -ci=*|--cert_id=*)
        CERT_ID="${i#*=}"
        if [ -n "$CERT_ID" ]; then
          SIGN=true
        fi
        shift # past argument=value
        ;;
    *)
        # unknown option
        ;;
esac
done

bash $SCRIPTS_PATH/internal/2a_bundle.sh -i=$INSTALL_PATH $QT_DIR_OPTION $MAC_M1_OPTION

echo "======= AppBundle Created ======="

if [ "$SIGN" = true ] ; then
    bash $SCRIPTS_PATH/internal/2b_sign_bundle.sh -i=$INSTALL_PATH -ci=$CERT_ID

    echo "======= Bundle Signed ======="
fi
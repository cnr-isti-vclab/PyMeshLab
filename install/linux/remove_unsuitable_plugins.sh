#!/bin/bash

cd "$(dirname "$(realpath "$0")")"; #move to script directory

FILENAME='../unsuitable_plugins.txt'
PLUGINS_DIR='../../pymeshlab/lib/meshlab/plugins'

while read line; do

if [[ $line != \#*  ]]
then
    rm $PLUGINS_DIR/*$line*
fi

done < $FILENAME

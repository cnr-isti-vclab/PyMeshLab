#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd $DIR #move to script directory

FILENAME='../unsuitable_plugins.txt'
PLUGINS_DIR='../../pymeshlab/lib/plugins'

while read line; do

if [[ $line != \#*  ]]
then
    rm $PLUGINS_DIR/*$line*
fi

done < $FILENAME

#!/bin/bash

sudo apt-get install -y mesa-common-dev libglu1-mesa-dev
sudo apt-get install -y make ninja-build patchelf libgmp-dev libmpfr-dev libxerces-c-dev
sudo apt-get install -y libtbb-dev

#needed by qt 5.15 on linux
sudo apt-get install libxkbcommon-x11-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-keysyms1-dev libxcb-render-util0-dev libxcb-xinerama0-dev
# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.18)
project(PyMeshLab)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab"
		CACHE PATH "default pymeshlab install directory" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

#####
# Developing options:
# - option to debug (call all the functions from c++ instead of python) -> debug_main.cpp
# - option to update automatically the list of filters doc page -> doc_main.cpp
#####
option(PYMESHLAB_BUILD_DEBUG "Debug PyMeshLab from C++, using the src/pymeshlab/debug_main.cpp source" OFF)
option(PYMESHLAB_UPDATE_DOC "Config used to update the list of filters doc page" OFF)

#####
# Option used on macos to deploy pymeshlab.
# Since macdeployqt needs an appbundle, this option puts the pymeshlab library
# everything required to run it in an appbundle, creating also a dubby binary
# needed by macdeployqt to deploy the Qt libraries.
# The script scripts/macOS/2_deploy.sh will then take care to transform the
# deployed appbundle in a proper pymeshlab python module.
#####
if (APPLE)
	option(PYMESHLAB_BUILD_DUMMY_BIN_MAC_DEPLOY "Build a dummy binary necessary to deploy pymeshlab in MacOS" OFF)
endif()

add_subdirectory(src)

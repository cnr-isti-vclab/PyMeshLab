# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../pymeshlab" 
	  CACHE PATH "default pymeshlab install directory" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

######
# Option to not build meshlab-common and all the plugins
# 
# If the option is set to OFF, the build system will assume that
# meshlab-common and the meshlab-plugins are built in the directory
# ${PYMESHLAB_BUILD_DISTRIB_DIR}/lib.
# The tree should be this:
#
# ${PYMESHLAB_BUILD_DISTRIB_DIR}
#  |
#  - lib
#     |
#     - libmeshlab-common.so
#     - ... eventually other deployed libs
#     - plugins
#        |
#        - libfilter_*.so
#        - ...
#
# Default is ON
# It is useful set this to OFF if you have an already built meshlab backup that
# will speed-up the pymeshlab build!
######
option(BUILD_MESHLAB "Build MeshLab components before PyMeshLab" ON)

#####
# Developing options:
# - option to debug (call all the functions from c++ instead of python) -> debug_main.cpp
# - option to update automatically the list of filters doc page -> doc_main.cpp
#####
option(BUILD_PYMESHLAB_DEBUG "Debug PyMeshLab from C++, using the src/pymeshlab/debug_main.cpp source" OFF)
option(BUILD_PYMESHLAB_UPDATE_DOC "Config used to update the list of filters doc page" OFF)

#####
# Option used on macos to deploy pymeshlab.
# Since macdeployqt needs an appbundle, this option puts the pymeshlab library
# everything required to run it in an appbundle, creating also a dubby binary
# needed by macdeployqt to deploy the Qt libraries.
# The script scripts/macOS/2_deploy.sh will then take care to transform the
# deployed appbundle in a proper pymeshlab python module.
#####
if (APPLE)
	option(BUILD_DUMMY_BIN_MAC_DEPLOY "Build a dummy binary necessary to deploy pymeshlab in MacOS" OFF)
endif()

## Required libraries:
# - OpenGL (ToDo: remove this)
# - Qt5 - OpenGL, Xml
# - Glew  (with fallback) (ToDo: remove this)
# - Eigen3 (with fallback)
# - OpenMP (not required)
# - Python

find_package(OpenGL REQUIRED)
find_package(
	Qt5
	COMPONENTS OpenGL Xml
	REQUIRED)

message(STATUS "Searching for required components with bundled fallback")

find_package(GLEW)
find_package(Eigen3)
find_package(OpenMP)
find_package(Qt5Qml)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PYMESHLAB_BUILD_DISTRIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/distrib/pymeshlab)

set(MESHLAB_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab/src")

add_definitions(-DMESHLAB_SCALAR=double)
set(BUILD_WITH_DOUBLE_SCALAR ON)

set(EXTERNAL_DIR ${MESHLAB_SRC_DIR}/external)

# VCGLib -- required
if(NOT VCGDIR)
	get_filename_component(VCGDIR "${MESHLAB_SRC_DIR}/vcglib" ABSOLUTE)
	if(NOT EXISTS ${VCGDIR})
		set(VCGDIR NOTFOUND)
	endif()
endif()
set(VCGDIR "${VCGDIR}")

if(NOT VCGDIR)
	message(FATAL_ERROR "VCGLib not found. Please clone recursively the MeshLab repo.")
endif()

#external
include(${EXTERNAL_DIR}/external_common.cmake)
add_subdirectory(${EXTERNAL_DIR})


if (APPLE AND BUILD_DUMMY_BIN_MAC_DEPLOY)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utilities/dummy_bin_mac_deploy)
endif()

if (BUILD_MESHLAB)
	include(${CMAKE_CURRENT_SOURCE_DIR}/meshlab.cmake)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab)

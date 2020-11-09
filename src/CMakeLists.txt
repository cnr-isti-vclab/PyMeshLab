# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

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

if (APPLE)
	option(BUILD_DUMMY_BIN_MAC_DEPLOY "Build a dummy binary necessary to deploy pymeshlab in MacOS" OFF)
endif()

## Required libraries:
# - OpenGL (ToDo: remove this)
# - Qt5 - OpenGL, Xml, XmlPatterns
# - Glew  (with fallback) (ToDo: remove this)
# - Eigen3 (with fallback)
# - OpenMP (not required)
# - Python

find_package(OpenGL REQUIRED)
find_package(
	Qt5
	COMPONENTS OpenGL Xml XmlPatterns
	REQUIRED)

message(STATUS "Searching for required components with bundled fallback")

find_package(GLEW)
find_package(Eigen3)
find_package(OpenMP)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PYMESHLAB_BUILD_DISTRIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/distrib/pymeshlab)

set(MESHLAB_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab/src")

add_definitions(-DMESHLAB_SCALAR=float)

set(EXTERNAL_DIR ${MESHLAB_SRC_DIR}/external)
include(${MESHLAB_SRC_DIR}/external_common.cmake)

if (APPLE AND BUILD_DUMMY_BIN_MAC_DEPLOY)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utilities/dummy_bin_mac_deploy)
endif()

if (BUILD_MESHLAB)
	include(${CMAKE_CURRENT_SOURCE_DIR}/meshlab.cmake)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab)

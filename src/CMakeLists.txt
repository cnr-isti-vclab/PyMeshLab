# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

find_package(OpenGL REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PYMESHLAB_BUILD_DISTRIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/pymeshlab)


set(MESHLAB_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab/src")
set(EXTERNAL_DIR ${MESHLAB_SRC_DIR}/external)
include(${MESHLAB_SRC_DIR}/external_common.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/meshlab.cmake)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab)



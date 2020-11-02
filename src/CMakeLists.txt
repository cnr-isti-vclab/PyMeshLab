# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

option(BUILD_MESHLAB ON)

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

if (BUILD_MESHLAB)
	include(${CMAKE_CURRENT_SOURCE_DIR}/meshlab.cmake)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab)

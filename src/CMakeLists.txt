# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.10)
project(PyMeshLab)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../pymeshlab"
		CACHE PATH "default pymeshlab install directory" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

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

# MeshLab directory
set(MESHLAB_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab/src")

# general meshlab build settings that apply also in pymeshlab:
include("${MESHLAB_SRC_DIR}/cmake/meshlab_global_settings.cmake")

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
	COMPONENTS OpenGL Xml Network
	REQUIRED)

message(STATUS "Searching for required components with bundled fallback")

find_package(GLEW)
find_package(Eigen3)
find_package(OpenMP)

### Build settings
set(PYMESHLAB_BUILD_DISTRIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/distrib/pymeshlab)

list(APPEND CMAKE_MODULE_PATH "${MESHLAB_SRC_DIR}/cmake")
add_definitions(-DMESHLAB_SCALAR=double)
set(MESHLAB_BUILD_WITH_DOUBLE_SCALAR ON)

set(EXTERNAL_DIR ${MESHLAB_SRC_DIR}/external)

if (APPLE AND BUILD_DUMMY_BIN_MAC_DEPLOY)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utilities/dummy_bin_mac_deploy)
endif()

set(MESHLAB_BUILD_ONLY_LIBRARIES ON)
set(MESHLAB_USE_DEFAULT_BUILD_AND_INSTALL_DIRS OFF)

### Build directories
if (NOT BUILD_DUMMY_BIN_MAC_DEPLOY)
	set(MESHLAB_BUILD_DISTRIB_DIR ${PYMESHLAB_BUILD_DISTRIB_DIR}/lib)
	if (NOT APPLE)
		set(MESHLAB_PLUGIN_OUTPUT_DIR ${MESHLAB_BUILD_DISTRIB_DIR}/plugins)
	else()
		set(MESHLAB_PLUGIN_OUTPUT_DIR ${PYMESHLAB_BUILD_DISTRIB_DIR}/PlugIns)
	endif()
else()
	set(MESHLAB_BUILD_DISTRIB_DIR ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/Frameworks)
	set(MESHLAB_PLUGIN_OUTPUT_DIR ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/PlugIns)
endif()
set(MESHLAB_LIB_OUTPUT_DIR ${MESHLAB_BUILD_DISTRIB_DIR})

### Install directories
MESSAGE( STATUS "CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX} )

if (WIN32)
	set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX})
	set(MESHLAB_PLUGIN_INSTALL_DIR ${MESHLAB_LIB_INSTALL_DIR}/lib/plugins)
elseif(NOT APPLE)
	set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)
	set(MESHLAB_PLUGIN_INSTALL_DIR ${MESHLAB_LIB_INSTALL_DIR}/plugins)
else(APPLE)
	if(BUILD_DUMMY_BIN_MAC_DEPLOY)
		set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents/Frameworks)
		set(MESHLAB_PLUGIN_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents/PlugIns)
	else()
		set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Frameworks)
		set(MESHLAB_PLUGIN_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/PlugIns)
	endif()
endif()

set(MESHLAB_PLUGINS
	# IO plugins
	meshlabplugins/io_3ds
	meshlabplugins/io_base
	meshlabplugins/io_bre
	meshlabplugins/io_collada
	meshlabplugins/io_ctm
	meshlabplugins/io_e57
	meshlabplugins/io_expe
	meshlabplugins/io_json
	meshlabplugins/io_gltf
	meshlabplugins/io_pdb
	meshlabplugins/io_tri
	meshlabplugins/io_txt
	meshlabplugins/io_u3d
	meshlabplugins/io_x3d

	# Filter plugins
	meshlabplugins/filter_sample
	meshlabplugins/filter_createiso
	meshlabplugins/filter_geodesic
	meshlabplugins/filter_sample_gpu
	meshlabplugins/filter_ao
	meshlabplugins/filter_camera
	meshlabplugins/filter_clean
	meshlabplugins/filter_color_projection
	meshlabplugins/filter_colorproc
	meshlabplugins/filter_create
	meshlabplugins/filter_dirt
	meshlabplugins/filter_fractal
	meshlabplugins/filter_func
	meshlabplugins/filter_icp
	meshlabplugins/filter_img_patch_param
	meshlabplugins/filter_io_nxs
	meshlabplugins/filter_isoparametrization
	meshlabplugins/filter_layer
	meshlabplugins/filter_measure
	meshlabplugins/filter_mesh_booleans
	meshlabplugins/filter_meshing
	meshlabplugins/filter_mls
	meshlabplugins/filter_mutualglobal
	meshlabplugins/filter_mutualinfo
	meshlabplugins/filter_parametrization
	meshlabplugins/filter_plymc
	meshlabplugins/filter_qhull
	meshlabplugins/filter_quality
	meshlabplugins/filter_sampling
	meshlabplugins/filter_screened_poisson
	meshlabplugins/filter_sdfgpu
	meshlabplugins/filter_select
	meshlabplugins/filter_sketchfab
	meshlabplugins/filter_ssynth
	meshlabplugins/filter_texture
	meshlabplugins/filter_texture_defragmentation
	meshlabplugins/filter_trioptimize
	meshlabplugins/filter_unsharp
	meshlabplugins/filter_voronoi
)

add_subdirectory(meshlab/src)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab)

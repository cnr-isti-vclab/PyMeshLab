# Copyright 2019 Collabora, Ltd.
# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.10)
project(PyMeshLab)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../pymeshlab"
		CACHE PATH "default pymeshlab install directory" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

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
set(BUILD_WITH_DOUBLE_SCALAR ON)

set(EXTERNAL_DIR ${MESHLAB_SRC_DIR}/external)

if (APPLE AND BUILD_DUMMY_BIN_MAC_DEPLOY)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utilities/dummy_bin_mac_deploy)
endif()

if (BUILD_MESHLAB)
	set(BUILD_ONLY_MESHLAB_LIBRARIES ON)
	set(USE_DEFAULT_BUILD_AND_INSTALL_DIRS OFF)

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
else()
	# VCGLib -- required
	if (VCGDIR) # VCGDIR exists - using custom user vcglib path
		if(EXISTS ${VCGDIR})
			add_subdirectory(${VCGDIR} {CMAKE_CURRENT_BINARY_DIR}/vcglib)
			message(STATUS "- VCGLib - using custom VCGDIR path library")
		else()
			set(VCGDIR NOTFOUND)
		endif()
	else()
		get_filename_component(VCGDIR "${MESHLAB_SRC_DIR}/vcglib" ABSOLUTE)
		if(EXISTS ${VCGDIR})
			add_subdirectory(${VCGDIR})
			message(STATUS "- VCGLib - using using bundled source")
		else()
			set(VCGDIR NOTFOUND)
		endif()
	endif()
	set(VCGDIR "${VCGDIR}")

	if(NOT VCGDIR)
		message(FATAL_ERROR "VCGLib not found. Please clone recursively the MeshLab repo.")
	endif()

	#external
	set(ALLOW_OPTIONAL_EXTERNAL_MESHLAB_LIBRARIES OFF)
	add_subdirectory(${EXTERNAL_DIR})
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab)

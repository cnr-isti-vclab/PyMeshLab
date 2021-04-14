# Copyright 2019, 2020, Collabora, Ltd.
# Copyright 2019, 2020, Visual Computing Lab, ISTI - Italian National Research Council
# SPDX-License-Identifier: BSL-1.0

include(${MESHLAB_SRC_DIR}/cmake/meshlab_global_settings.cmake)
include(${MESHLAB_SRC_DIR}/cmake/meshlab_tools.cmake)

### Build options
option(BUILD_STRICT "Strictly enforce resolution of all symbols" ON)
option(BUILD_MESHLABSERVER "Build meshlabserver" OFF)
option(BUILD_DEBUG_MESHLAB_FILTERS_ONLY "Build just a small set of filters for debug" OFF)

option(MESHLAB_IS_RELEASE_CANDIDATE_VERSION "" OFF)
option(MESHLAB_IS_NIGHTLY_VERSION "" OFF)

### Dependencies
message(STATUS "Searching for required components")
#find_package(OpenGL REQUIRED)

message(STATUS "Searching for optional components")
find_package(Lib3ds)
find_package(GMP)
find_package(muparser)
find_package(OpenCTM)
find_package(Qhull COMPONENTS libqhull)

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
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MESHLAB_BUILD_DISTRIB_DIR})

### Build settings
include_directories(${MESHLAB_SRC_DIR})

### Install directories
MESSAGE( STATUS "CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX} )

if(NOT APPLE)
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

### Enter subdirectories

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
include(${EXTERNAL_DIR}/external_common.cmake)
add_subdirectory(${EXTERNAL_DIR})

add_subdirectory(${MESHLAB_SRC_DIR}/common)
if(BUILD_MESHLABSERVER)
	add_subdirectory(${MESHLAB_SRC_DIR}/meshlabserver)
endif()

### Plugin subdirectories
if (BUILD_DEBUG_MESHLAB_FILTERS_ONLY)
	set(MESHLAB_PLUGINS
		meshlabplugins/io_base
		meshlabplugins/filter_ao
		)
else()
	set(MESHLAB_PLUGINS
		# IO plugins
		meshlabplugins/io_3ds
		meshlabplugins/io_base
		meshlabplugins/io_bre
		meshlabplugins/io_collada
		meshlabplugins/io_ctm
		meshlabplugins/io_expe
		meshlabplugins/io_json
		meshlabplugins/io_pdb
		meshlabplugins/io_tri
		meshlabplugins/io_txt
		meshlabplugins/io_u3d
		meshlabplugins/io_x3d
	
		# IORaster plugins
		meshlabplugins/ioraster_base
	
		# Filter plugins
		meshlabplugins/filter_sample
		meshlabplugins/filter_sample_dyn
		meshlabplugins/filter_createiso
		meshlabplugins/filter_geodesic
		meshlabplugins/filter_sample_gpu
		meshlabplugins/filter_ao
		meshlabplugins/filter_camera
		meshlabplugins/filter_clean
		meshlabplugins/filter_color_projection
		meshlabplugins/filter_colorproc
		meshlabplugins/filter_create
		meshlabplugins/filter_csg
		meshlabplugins/filter_dirt
		meshlabplugins/filter_fractal
		meshlabplugins/filter_func
		meshlabplugins/filter_img_patch_param
		meshlabplugins/filter_isoparametrization
		meshlabplugins/filter_layer
		meshlabplugins/filter_measure
		meshlabplugins/filter_meshing
		meshlabplugins/filter_mls
		meshlabplugins/filter_mutualglobal
		meshlabplugins/filter_mutualinfo
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
		meshlabplugins/filter_trioptimize
		meshlabplugins/filter_unsharp
		meshlabplugins/filter_voronoi
	)
endif()

message(STATUS "\nConfiguring plugins")
foreach(PLUGIN ${MESHLAB_PLUGINS})
	if(EXISTS ${MESHLAB_SRC_DIR}/${PLUGIN}/CMakeLists.txt)
		message(STATUS "- ${PLUGIN}")
		add_subdirectory(${MESHLAB_SRC_DIR}/${PLUGIN})
	else()
		message(STATUS "  - ${PLUGIN} - Skipping, plugin or build system not found.")
	endif()
endforeach()

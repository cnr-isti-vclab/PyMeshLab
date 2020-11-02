# Prefer GLVND
if(POLICY CMP0072)
	cmake_policy(SET CMP0072 NEW)
endif()

### Build options
option(BUILD_STRICT "Strictly enforce resolution of all symbols" ON)

### Dependencies
list(APPEND CMAKE_MODULE_PATH "${MESHLAB_SRC_DIR}/cmake")
message(STATUS "Searching for required components")
#find_package(OpenGL REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

message(STATUS "Searching for optional components")
find_package(Lib3ds)
find_package(GMP)
find_package(muparser)
find_package(OpenCTM)
find_package(Qhull COMPONENTS libqhull)

### Build directories
set(MESHLAB_BUILD_DISTRIB_DIR ${PYMESHLAB_BUILD_DISTRIB_DIR}/lib)
set(MESHLAB_LIB_OUTPUT_DIR ${MESHLAB_BUILD_DISTRIB_DIR})
set(MESHLAB_PLUGIN_OUTPUT_DIR ${MESHLAB_BUILD_DISTRIB_DIR}/plugins)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MESHLAB_BUILD_DISTRIB_DIR})

### Build settings
include_directories(${MESHLAB_SRC_DIR})
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

### Settings needed for both "external" and internal code
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

### Build Settings
if(WIN32)
	add_definitions(-DNOMINMAX)
	if(MSVC)
		add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
	endif()
endif()

if(BUILD_STRICT AND NOT MSVC AND NOT APPLE)
	# Make sure that our shared libraries were appropriately linked
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
	set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined")
endif()

### Install directories
MESSAGE( STATUS "CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX} )

if(NOT WIN32 AND NOT APPLE)
	set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/meshlab)
	set(MESHLAB_PLUGIN_INSTALL_DIR ${MESHLAB_LIB_INSTALL_DIR}/plugins)
elseif(APPLE)
	set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/Frameworks)
	set(MESHLAB_PLUGIN_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/PlugIns)
elseif(WIN32)
	set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/meshlab)
	set(MESHLAB_PLUGIN_INSTALL_DIR ${MESHLAB_LIB_INSTALL_DIR}/plugins)
endif()

### Enter subdirectories

#external
include(${EXTERNAL_DIR}/external.cmake)


add_subdirectory(${MESHLAB_SRC_DIR}/common)

### Plugin subdirectories
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
	meshlabplugins/filter_globalregistration
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

message(STATUS "\nConfiguring plugins")
foreach(PLUGIN ${MESHLAB_PLUGINS})
	if(EXISTS ${MESHLAB_SRC_DIR}/${PLUGIN}/CMakeLists.txt)
		message(STATUS "- ${PLUGIN}")
		add_subdirectory(${MESHLAB_SRC_DIR}/${PLUGIN})
	else()
		message(STATUS "  - ${PLUGIN} - Skipping, plugin or build system not found.")
	endif()
endforeach()

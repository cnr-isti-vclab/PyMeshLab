cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

### Build options
option(BUILD_STRICT "Strictly enforce resolution of all symbols" ON)
option(BUILD_MESHLAB_LIBS "Build also MeshLab Libs" ON)

### Dependencies
list(APPEND CMAKE_MODULE_PATH "${MESHLAB_BASE_DIR}/src/cmake")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(
	Qt5
	COMPONENTS OpenGL Xml XmlPatterns Qml
	REQUIRED)
find_package(OpenMP)
#find_package(GLEW)
find_package(Eigen3)

find_package(OpenGL REQUIRED)
find_package(Lib3ds)
find_package(GMP)
find_package(muparser)
find_package(OpenCTM)
find_package(Qhull COMPONENTS libqhull)

set(PYBIND_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pybind11")
set(PYMESHLAB_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab")
set(MESHLAB_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab")
set(EXTERNAL_DIR "${MESHLAB_BASE_DIR}/src/external")
#set(PYMESHLAB_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../pymeshlab")

### Build settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_definitions(-DMESHLAB_SCALAR=float)
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
MESSAGE(STATUS "CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX})

if(WIN32 OR APPLE)
	set(INSTALL_TO_UNIX_LAYOUT OFF)
else()
	set(INSTALL_TO_UNIX_LAYOUT ON)
endif()
include(GNUInstallDirs)
if(INSTALL_TO_UNIX_LAYOUT)
	set(MESHLAB_BIN_INSTALL_DIR ${CMAKE_INSTALL_BINDIR})
	set(MESHLAB_LIB_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/meshlab)
	set(MESHLAB_PLUGIN_INSTALL_DIR ${MESHLAB_LIB_INSTALL_DIR}/plugins)
	set(MESHLAB_SHADER_INSTALL_DIR ${CMAKE_INSTALL_DATAROOTDIR}/meshlab/shaders)
	set(MESHLAB_SAMPLE_INSTALL_DIR ${CMAKE_INSTALL_DATAROOTDIR}/meshlab)
elseif(APPLE)
	set(MESHLAB_BIN_INSTALL_DIR .)
	set(MESHLAB_LIB_INSTALL_DIR meshlab.app/Contents/Frameworks)
	set(MESHLAB_PLUGIN_INSTALL_DIR meshlab.app/Contents/PlugIns)
	set(MESHLAB_SHADER_INSTALL_DIR meshlab.app/Contents/shaders)
	set(MESHLAB_SAMPLE_INSTALL_DIR .)
else()
	set(MESHLAB_BIN_INSTALL_DIR .)
	set(MESHLAB_LIB_INSTALL_DIR .)
	set(MESHLAB_PLUGIN_INSTALL_DIR plugins)
	set(MESHLAB_SHADER_INSTALL_DIR shaders)
	set(MESHLAB_SAMPLE_INSTALL_DIR .)
endif()

### Install Settings
if (NOT APPLE)
	set(CMAKE_INSTALL_RPATH $ORIGIN/../${MESHLAB_LIB_INSTALL_DIR};$ORIGIN/../${CMAKE_INSTALL_LIBDIR})
else()
	SET(CMAKE_INSTALL_RPATH $ORIGIN/../Frameworks)
endif()


### Common includes
include(${MESHLAB_BASE_DIR}/src/external_common.cmake)

add_subdirectory(${MESHLAB_BASE_DIR}/src/common)
add_subdirectory(${PYMESHLAB_BASE_DIR})

if (BUILD_MESHLAB_LIBS)
	include(${EXTERNAL_DIR}/external.cmake)
	include_directories(${MESHLAB_BASE_DIR}/src/common)
	
	set(PLUGINS
		# IO plugins
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_3ds
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_base
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_bre
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_collada
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_ctm
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_expe
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_json
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_pdb
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_tri
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_txt
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_u3d
		${MESHLAB_BASE_DIR}/src/meshlabplugins/io_x3d
		
		# Filter plugins
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_ao
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_camera
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_clean
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_color_projection
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_colorproc
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_create
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_csg
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_dirt
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_fractal
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_func
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_globalregistration
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_img_patch_param
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_isoparametrization
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_layer
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_measure
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_meshing
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_mls
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_mutualglobal
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_mutualinfo
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_plymc
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_qhull
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_quality
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_sampling
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_screened_poisson
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_sdfgpu
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_select
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_sketchfab
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_ssynth
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_texture
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_trioptimize
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_unsharp
		${MESHLAB_BASE_DIR}/src/meshlabplugins/filter_voronoi
	)

	foreach(PLUGIN ${PLUGINS})
		message(STATUS "- ${PLUGIN}")
		add_subdirectory(${PLUGIN})
	endforeach()
endif()



install(TARGETS ${PYMESHLAB_MODULE_NAME} DESTINATION ${PYMESHLAB_INSTALL_DIR})
install(TARGETS common DESTINATION "${PYMESHLAB_INSTALL_DIR}/lib")

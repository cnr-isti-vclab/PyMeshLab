cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

### Build options
option(BUILD_PLUGINS "Build MeshLab plugins" ON)

#definitions
add_definitions(-DMESHLAB_SCALAR=float)

#directories
set(PYBIND_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pybind11")
set(PYMESHLAB_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pymeshlab")
set(MESHLAB_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab")
set(EXTERNAL_DIR "${MESHLAB_BASE_DIR}/src/external")
get_filename_component(VCG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/meshlab/vcglib" ABSOLUTE)
set(PYMESHLAB_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../pymeshlab")

### Dependencies
list(APPEND CMAKE_MODULE_PATH "${MESHLAB_BASE_DIR}/src/cmake")

#Qt
find_package(
    Qt5
    COMPONENTS Core OpenGL Xml Qml XmlPatterns
    REQUIRED)

#Eigen
find_package(Eigen3)
if (NOT EIGEN3_INCLUDE_DIR)
	set(EIGEN_INCLUDE_DIRS  ${VCG_DIR}/eigenlib)
endif()

#glew
find_package(GLEW)
set(GLEW_DIR "${EXTERNAL_DIR}/glew-2.1.0")
if (NOT TARGET GLEW::GLEW)
	set(GLEW_INCLUDE_DIRS  ${GLEW_DIR}/include)
endif()

#openmp
find_package(OpenMP)

### Common includes
#Eigen
include_directories(${EIGEN_INCLUDE_DIRS})
#glew
include_directories(${GLEW_INCLUDE_DIRS})
#vcg
include_directories(${VCG_DIR})

add_subdirectory(${MESHLAB_BASE_DIR}/src/common)
add_subdirectory(${PYMESHLAB_BASE_DIR})

install(TARGETS ${PYMESHLAB_MODULE_NAME} DESTINATION ${PYMESHLAB_INSTALL_DIR})
install(TARGETS common DESTINATION "${PYMESHLAB_INSTALL_DIR}/lib")

if (BUILD_PLUGINS)
	include("${MESHLAB_BASE_DIR}/src/external.cmake")
	#dependencies
	find_package(Lib3ds)
	find_package(GMP)
	find_package(muparser)
	find_package(OpenCTM)
	find_package(Qhull COMPONENTS libqhull)
	
	
	
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

cmake_minimum_required(VERSION 3.9)
project(PyMeshLab)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
	bindings/pycolor.h
	bindings/pyboundingbox.h
	bindings/pyexceptions.h
	bindings/pymesh.h
	bindings/pymeshset.h
	bindings/pypercentage.h
	docs/pyboundingbox_doc.h
	docs/pycolor_doc.h
	docs/pyexceptions_doc.h
	docs/pymesh_doc.h
	docs/pymeshset_doc.h
	docs/pypercentage_doc.h
	pymeshlab/color.h
	pymeshlab/common.h
	pymeshlab/exceptions.h
	pymeshlab/mesh.h
	pymeshlab/meshlabsingletons.h
	pymeshlab/meshset.h
	pymeshlab/percentage.h
	pymeshlab/plugin_management/filterfunction.h
	pymeshlab/plugin_management/filterfunctionparameter.h
	pymeshlab/plugin_management/filterfunctionset.h
)

set(SOURCES
	bindings/pyexceptions.cpp
	main.cpp
	bindings/pyboundingbox.cpp
	bindings/pycolor.cpp
	bindings/pymesh.cpp
	bindings/pymeshset.cpp
	bindings/pypercentage.cpp
	pymeshlab/color.cpp
	pymeshlab/common.cpp
	pymeshlab/mesh.cpp
	pymeshlab/meshlabsingletons.cpp
	pymeshlab/meshset.cpp
	pymeshlab/percentage.cpp
	pymeshlab/plugin_management/filterfunction.cpp
	pymeshlab/plugin_management/filterfunctionparameter.cpp
	pymeshlab/plugin_management/filterfunctionset.cpp
)

#definitions
add_definitions(-DMESHLAB_SCALAR=float)

#directories
set(MESHLAB_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../meshlab")
set(MESHLAB_EXTERNAL_DIR "${MESHLAB_BASE_DIR}/src/external")
get_filename_component(VCG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../meshlab/vcglib" ABSOLUTE)

#pybind11
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../pybind11" pybind11)
pybind11_add_module(pymeshlab ${SOURCES} ${HEADERS})

#Qt
find_package(
    Qt5
    COMPONENTS Core OpenGL Xml Qml
    REQUIRED)
target_link_libraries(pymeshlab PRIVATE Qt5::OpenGL Qt5::OpenGL Qt5::Xml Qt5::Qml)

#Eigen
find_package(Eigen3)
if (NOT EIGEN3_INCLUDE_DIR)
	set(EIGEN_INCLUDE_DIRS  ${VCG_DIR}/eigenlib)
endif()
include_directories(${EIGEN_INCLUDE_DIRS})

#glew
find_package(GLEW)
set(GLEW_DIR "${MESHLAB_EXTERNAL_DIR}/glew-2.1.0")
if (NOT TARGET GLEW::GLEW)
	set(GLEW_INCLUDE_DIRS  ${GLEW_DIR}/include)
endif()
include_directories(${GLEW_INCLUDE_DIRS})

#vcg
include_directories(${VCG_DIR})

#meshlab_common
include_directories("${MESHLAB_BASE_DIR}/src/common")






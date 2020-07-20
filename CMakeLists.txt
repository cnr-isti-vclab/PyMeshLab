cmake_minimum_required(VERSION 2.8.12)
project(pymeshlab)

find_package(OpenGL REQUIRED)

find_package(
	Qt5 REQUIRED COMPONENTS Core OpenGL Xml)

include_directories(
	meshlab/vcglib
	meshlab/vcglib/eigenlib
	meshlab/src/external/glew-2.1.0/include
	meshlab/src/common
	)

add_definitions(-DMESHLAB_SCALAR=float)

add_subdirectory(pybind11)

pybind11_add_module(
	pymeshlab
	src/pymeshlab.cpp)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/PyMeshLab/lib)
	message("lib exists")
else()
	message("lib does not exists")
endif()

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/PyMeshLab/lib)

target_link_libraries(
	pymeshlab PUBLIC
	OpenGL::GLU
	Qt5::Core
	Qt5::OpenGL
	Qt5::Xml
	${CMAKE_CURRENT_SOURCE_DIR}/PyMeshLab/lib/meshlab-common.lib)

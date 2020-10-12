set(PYMESHLAB_MODULE_NAME "pmeshlab")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
	bindings/pycamera.h
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
	main.cpp
	bindings/pycamera.cpp
	bindings/pycolor.cpp
	bindings/pyboundingbox.cpp
	bindings/pyexceptions.cpp
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

#pybind11
add_subdirectory("${PYBIND_BASE_DIR}" pybind11)
pybind11_add_module(${PYMESHLAB_MODULE_NAME} ${SOURCES} ${HEADERS})

#Qt
target_link_libraries(${PYMESHLAB_MODULE_NAME} PRIVATE Qt5::OpenGL Qt5::OpenGL Qt5::Xml Qt5::Qml)

#meshlab_common
include_directories("${MESHLAB_BASE_DIR}/src/common")
target_link_libraries(${PYMESHLAB_MODULE_NAME} PRIVATE common)



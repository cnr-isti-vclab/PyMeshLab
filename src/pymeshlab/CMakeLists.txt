set(PYMESHLAB_MODULE_NAME "pmeshlab")

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${MESHLAB_SRC_DIR}/common)

#pybind11
add_subdirectory(pybind11)
pybind11_add_module(${PYMESHLAB_MODULE_NAME} ${HEADERS} ${SOURCES})

#python
target_link_libraries(${PYMESHLAB_MODULE_NAME} PRIVATE pybind11::embed)

#Qt
target_link_libraries(${PYMESHLAB_MODULE_NAME} PRIVATE Qt5::OpenGL Qt5::OpenGL Qt5::Xml external-glew)

#meshlab-common
if (NOT BUILD_MESHLAB)
	target_link_directories(${PYMESHLAB_MODULE_NAME} PUBLIC "${PYMESHLAB_BUILD_DISTRIB_DIR}/lib")
endif()
target_link_libraries(${PYMESHLAB_MODULE_NAME} PUBLIC meshlab-common)

set_property(TARGET ${PYMESHLAB_MODULE_NAME} 
	PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})

set_property(TARGET ${PYMESHLAB_MODULE_NAME} 
	PROPERTY LIBRARY_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
install(TARGETS ${PYMESHLAB_MODULE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
if (NOT APPLE)
	set_target_properties(${PYMESHLAB_MODULE_NAME} PROPERTIES 
		INSTALL_RPATH "\$ORIGIN/lib:${INSTALL_RPATH}")
else()
	set_target_properties(${PYMESHLAB_MODULE_NAME} PROPERTIES
		INSTALL_RPATH "\$ORIGIN/Frameworks:${INSTALL_RPATH}")
endif()

### Copy/install other files
if (NOT BUILD_MESHLAB)
	install(DIRECTORY "${PYMESHLAB_BUILD_DISTRIB_DIR}/lib" DESTINATION ${CMAKE_INSTALL_PREFIX})
endif()

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${CMAKE_INSTALL_PREFIX})

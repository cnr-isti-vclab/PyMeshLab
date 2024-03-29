set(PYMESHLAB_MODULE_NAME "pmeshlab")

set(HEADERS
	bindings/pycamera.h
	bindings/pycolor.h
	bindings/pyboundingbox.h
	bindings/pyexceptions.h
	bindings/pyimage.h
	bindings/pymesh.h
	bindings/pymeshset.h
	bindings/pymodule_functions.h
	bindings/pypercentage_value.h
	bindings/pypure_value.h
	docs/pyboundingbox_doc.h
	docs/pycolor_doc.h
	docs/pyexceptions_doc.h
	docs/pyimage_doc.h
	docs/pymesh_doc.h
	docs/pymeshset_doc.h
	docs/pymodule_functions_doc.h
	docs/pypercentage_value_doc.h
	docs/pypure_value_doc.h
	pymeshlab/bounding_box.h
	pymeshlab/color.h
	pymeshlab/exceptions.h
	pymeshlab/image.h
	pymeshlab/mesh.h
	pymeshlab/meshset.h
	pymeshlab/module_functions.h
	pymeshlab/percentage_value.h
	pymeshlab/pure_value.h
	pymeshlab/helpers/common.h
	pymeshlab/helpers/meshset_helper.h
	pymeshlab/helpers/verbosity_manager.h
)

set(SOURCES
	main.cpp
	bindings/pycamera.cpp
	bindings/pycolor.cpp
	bindings/pyboundingbox.cpp
	bindings/pyexceptions.cpp
	bindings/pyimage.cpp
	bindings/pymesh.cpp
	bindings/pymeshset.cpp
	bindings/pymodule_functions.cpp
	bindings/pypercentage_value.cpp
	bindings/pypure_value.cpp
	pymeshlab/bounding_box.cpp
	pymeshlab/color.cpp
	pymeshlab/image.cpp
	pymeshlab/mesh.cpp
	pymeshlab/meshset.cpp
	pymeshlab/module_functions.cpp
	pymeshlab/percentage_value.cpp
	pymeshlab/pure_value.cpp
	pymeshlab/helpers/common.cpp
	pymeshlab/helpers/meshset_helper.cpp
	pymeshlab/helpers/verbosity_manager.cpp
)

#version management
string(TIMESTAMP PYMESHLAB_VERSION "%Y.%m")
if (MESHLAB_IS_NIGHTLY_VERSION)
	# nightly version is in the form:
	# YYYY.mm[d]_nightly_GIT_SHA1
	# YYYY and mm are computed by cmake and not read from file
	find_package(Git)
	execute_process(COMMAND
		"${GIT_EXECUTABLE}" describe --match=NeVeRmAtCh --always --abbrev=7
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_VARIABLE GIT_SHA1
		ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
	set(PYMESHLAB_VERSION "${PYMESHLAB_VERSION}_nightly_${GIT_SHA1}")
else()
	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../PYML_VERSION")
		file(READ "${CMAKE_CURRENT_SOURCE_DIR}/../../PYML_VERSION" PYMESHLAB_VERSION)
	endif()
endif()
add_definitions(-DPYMESHLAB_VERSION=${PYMESHLAB_VERSION})
message(STATUS "PyMeshLab version: ${PYMESHLAB_VERSION}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${MESHLAB_SRC_DIR})

#pybind11
add_subdirectory(pybind11)
if ((NOT PYMESHLAB_BUILD_DEBUG) AND (NOT PYMESHLAB_UPDATE_DOC))
	pybind11_add_module(${PYMESHLAB_MODULE_NAME} ${HEADERS} ${SOURCES})
endif()

##### OTHER OPTIONS - debug or doc
if (PYMESHLAB_BUILD_DEBUG) #bin to debug pymeshlab
	add_definitions(-DPYMESHLAB_DEBUG)
	list(APPEND SOURCES debug_main.cpp)
	add_executable(${PYMESHLAB_MODULE_NAME} ${SOURCES} ${HEADERS})
	target_link_libraries(
		${PYMESHLAB_MODULE_NAME}
		PUBLIC
			meshlab-common
			pybind11_headers
			${PYTHON_LIBRARIES})
	target_include_directories(
		${PYMESHLAB_MODULE_NAME}
		PUBLIC
			${PYTHON_INCLUDE_DIRS})
	set_property(TARGET ${PYMESHLAB_MODULE_NAME}
		PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
elseif(PYMESHLAB_UPDATE_DOC) #bin to update doc
	add_definitions(-DPYMESHLAB_SRC_BASE_DIR=${CMAKE_CURRENT_SOURCE_DIR})
	add_definitions(-DPYMESHLAB_DEBUG)
	list(APPEND SOURCES doc_main.cpp)
	add_executable(${PYMESHLAB_MODULE_NAME} ${SOURCES} ${HEADERS})
	target_link_libraries(
		${PYMESHLAB_MODULE_NAME}
		PUBLIC
			meshlab-common)
	set_property(TARGET ${PYMESHLAB_MODULE_NAME}
		PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
endif()
##### END OTHER OPTIONS

#python
if (NOT WIN32 AND NOT APPLE)
	target_link_libraries(${PYMESHLAB_MODULE_NAME} PRIVATE pybind11::embed)
endif()

#Qt
target_link_libraries(${PYMESHLAB_MODULE_NAME} PRIVATE Qt5::OpenGL Qt5::Xml external-glew)
target_link_libraries(
	${PYMESHLAB_MODULE_NAME}
	PUBLIC meshlab-common)

### Build directories
if (NOT PYMESHLAB_BUILD_DUMMY_BIN_MAC_DEPLOY)
	#set_property(TARGET ${PYMESHLAB_MODULE_NAME}
	#	PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
	set_property(TARGET ${PYMESHLAB_MODULE_NAME}
		PROPERTY LIBRARY_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
else()
	set_property(TARGET ${PYMESHLAB_MODULE_NAME}
		PROPERTY LIBRARY_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
endif()

#copy files on build
if (NOT PYMESHLAB_BUILD_DUMMY_BIN_MAC_DEPLOY)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/polyscope_functions.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/replacer.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
else()
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/polyscope_functions.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/replacer.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
endif()

### Install directories
if (PYMESHLAB_BUILD_DUMMY_BIN_MAC_DEPLOY)
	install(TARGETS ${PYMESHLAB_MODULE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
else()
	install(TARGETS ${PYMESHLAB_MODULE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
endif()

if (NOT APPLE)
	set_target_properties(${PYMESHLAB_MODULE_NAME} PROPERTIES
		INSTALL_RPATH "\$ORIGIN/lib:${INSTALL_RPATH}")
else()
	set_target_properties(${PYMESHLAB_MODULE_NAME}
		PROPERTIES
			INSTALL_RPATH_USE_LINK_PATH TRUE)
	add_custom_command(
		TARGET ${PYMESHLAB_MODULE_NAME}
		POST_BUILD COMMAND
		${CMAKE_INSTALL_NAME_TOOL} -add_rpath "@loader_path/Frameworks" $<TARGET_FILE:${PYMESHLAB_MODULE_NAME}>)
endif()

if (NOT PYMESHLAB_BUILD_DUMMY_BIN_MAC_DEPLOY)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${CMAKE_INSTALL_PREFIX})
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${CMAKE_INSTALL_PREFIX})
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/polyscope_functions.py" DESTINATION ${CMAKE_INSTALL_PREFIX})
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/replacer.py" DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/polyscope_functions.py" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/replacer.py" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
endif()

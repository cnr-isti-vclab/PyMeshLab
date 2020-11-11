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
if ((NOT BUILD_PYMESHLAB_DEBUG) AND (NOT BUILD_PYMESHLAB_UPDATE_DOC))
	pybind11_add_module(${PYMESHLAB_MODULE_NAME} ${HEADERS} ${SOURCES})
endif()

##### OTHER OPTIONS - debug or doc
if (BUILD_PYMESHLAB_DEBUG) #bin to debug pymeshlab
	add_definitions(-DPYMESHLAB_DEBUG)
	list(APPEND SOURCES debug_main.cpp)
	add_executable(${PYMESHLAB_MODULE_NAME} ${SOURCES} ${HEADERS})
	target_link_libraries(
		${PYMESHLAB_MODULE_NAME} 
		PUBLIC  
			meshlab-common)
	set_property(TARGET ${PYMESHLAB_MODULE_NAME}
		PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
elseif(BUILD_PYMESHLAB_UPDATE_DOC) #bin to update doc
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

#meshlab-common
if (NOT BUILD_MESHLAB)
	if (NOT BUILD_DUMMY_BIN_MAC_DEPLOY)
		target_link_directories(${PYMESHLAB_MODULE_NAME} PUBLIC "${PYMESHLAB_BUILD_DISTRIB_DIR}/lib")
	else()
		target_link_directories(${PYMESHLAB_MODULE_NAME} PUBLIC "${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/Frameworks")
	endif()
endif()
target_link_libraries(${PYMESHLAB_MODULE_NAME} PUBLIC meshlab-common)

### Build directories
if (NOT BUILD_DUMMY_BIN_MAC_DEPLOY)
	#set_property(TARGET ${PYMESHLAB_MODULE_NAME} 
	#	PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
	set_property(TARGET ${PYMESHLAB_MODULE_NAME} 
		PROPERTY LIBRARY_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})
else()
	set_property(TARGET ${PYMESHLAB_MODULE_NAME} 
		PROPERTY LIBRARY_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
endif()

#copy files on build
if (NOT BUILD_DUMMY_BIN_MAC_DEPLOY)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR})
else()
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents)
endif()

### Install directories
if (BUILD_DUMMY_BIN_MAC_DEPLOY)
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

### Copy/install other files
if (NOT BUILD_MESHLAB)
	if (NOT BUILD_DUMMY_BIN_MAC_DEPLOY)
		install(DIRECTORY "${PYMESHLAB_BUILD_DISTRIB_DIR}/lib" DESTINATION ${CMAKE_INSTALL_PREFIX})
	else()
		install(DIRECTORY "${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/Frameworks" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents/Frameworks)
		install(DIRECTORY "${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/PlugIns" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents/PlugIns)
	endif()
endif()

if (NOT BUILD_DUMMY_BIN_MAC_DEPLOY)
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${CMAKE_INSTALL_PREFIX})
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/tests" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../../pymeshlab/__init__.py" DESTINATION ${CMAKE_INSTALL_PREFIX}/dummybin.app/Contents)
endif()

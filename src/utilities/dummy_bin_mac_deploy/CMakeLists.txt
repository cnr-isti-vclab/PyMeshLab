set(SOURCES
	main.cpp)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE STRING "Minimum OS X deployment version" FORCE)

add_executable(dummybin MACOSX_BUNDLE
	${SOURCES})

if (NOT BUILD_MESHLAB)
	target_include_directories(dummybin PUBLIC ${VCGDIR} ${EIGEN_INCLUDE_DIRS})
	target_link_directories(dummybin PUBLIC "${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/Frameworks")
	target_link_libraries(dummybin PUBLIC vcglib Qt5::Widgets external-glew)
endif()

target_link_libraries(dummybin PUBLIC meshlab-common)

include_directories(${MESHLAB_SRC_DIR}/common)

set_target_properties(dummybin
	PROPERTIES
		INSTALL_RPATH_USE_LINK_PATH TRUE)
add_custom_command(
	TARGET dummybin
	POST_BUILD COMMAND
	${CMAKE_INSTALL_NAME_TOOL} -add_rpath "@loader_path/Frameworks" $<TARGET_FILE:dummybin>)

set_property(TARGET dummybin
	PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})

set_target_properties(dummybin PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)

install(TARGETS dummybin DESTINATION ${CMAKE_INSTALL_PREFIX})

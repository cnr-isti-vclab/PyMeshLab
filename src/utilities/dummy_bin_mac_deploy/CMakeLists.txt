set(SOURCES
	main.cpp)

add_executable(dummybin MACOSX_BUNDLE
	${SOURCES})

if (NOT BUILD_MESHLAB)
	target_link_directories(dummybin PUBLIC "${PYMESHLAB_BUILD_DISTRIB_DIR}/dummybin.app/Contents/Frameworks")
	target_link_libraries(dummybin PUBLIC Qt5::Widgets)
endif()

target_link_libraries(dummybin PUBLIC meshlab-common)

include_directories(${MESHLAB_SRC_DIR}/common)

set_property(TARGET dummybin
	PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PYMESHLAB_BUILD_DISTRIB_DIR})

set_target_properties(dummybin PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)

install(TARGETS dummybin DESTINATION ${CMAKE_INSTALL_PREFIX})

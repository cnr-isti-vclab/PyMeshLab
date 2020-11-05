set(SOURCES
	main.cpp)

add_executable(dummybin MACOSX_BUNDLE
	${SOURCES})

target_link_libraries(
	dummybin
	PUBLIC meshlab-common
	)


set_target_properties(dummybin PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
#set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/images/meshlab.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images/meshlab.icns DESTINATION "${MESHLAB_BUILD_DISTRIB_DIR}/meshlab.app/Contents/Resources/")
#set_target_properties(meshlab PROPERTIES MACOSX_BUNDLE_ICONFILE meshlab.icns)

install(TARGETS dummybin DESTINATION ${CMAKE_INSTALL_PREFIX})

set(SOURCES
	main.cpp)

add_executable(dummybin MACOSX_BUNDLE
	${SOURCES})

target_link_libraries(
	dummybin
	PUBLIC meshlab-common
	)


set_target_properties(dummybin PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)

install(TARGETS dummybin DESTINATION ${CMAKE_INSTALL_PREFIX})

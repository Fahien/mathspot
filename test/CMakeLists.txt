# Sources
set( TEST_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/main-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/size-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/vec2-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/vec3-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/mat4-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/quat-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/rect-test.cc
	${CMAKE_CURRENT_SOURCE_DIR}/misc-test.cc
)
source_group( test FILES ${TEST_SOURCES} )

# Executable
add_executable( test-${PROJECT_NAME} ${TEST_SOURCES} )
target_link_libraries( test-${PROJECT_NAME} CONAN_PKG::catch2 ${PROJECT_NAME} )

include( CTest )
include( Catch )
catch_discover_tests( test-${PROJECT_NAME} )

cmake_minimum_required( VERSION 3.15 )
project( mathspot
	VERSION 0.5
	LANGUAGES C CXX
)

# Conan
if( NOT TARGET CONAN_PKG::catch2 )
	# Download automatically, you can also just copy the conan.cmake file
	if( NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake" )
		message( STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan" )
		file( DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
			"${CMAKE_BINARY_DIR}/conan.cmake" )
	endif()
	include( ${CMAKE_BINARY_DIR}/conan.cmake )
	conan_cmake_run( CONANFILE conanfile.txt BASIC_SETUP CMAKE_TARGETS BUILD missing )
endif()

# Includes
set( MST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include )

# Sources
set(MST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src )
set(SOURCES ${MST_SOURCE_DIR}/math.cc )
source_group(Sources FILES ${SOURCES} )

set(CMAKE_C_STANDARD   11 )
set(CMAKE_CXX_STANDARD 17 )

# Library
add_library( ${PROJECT_NAME} ${SOURCES} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${MST_INCLUDE_DIR} )

# Test
set( MST_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test )

# Sources
set( TEST_SOURCES
	${MST_TEST_DIR}/main-test.cc
	${MST_TEST_DIR}/size-test.cc
	${MST_TEST_DIR}/vec2-test.cc
	${MST_TEST_DIR}/vec3-test.cc
	${MST_TEST_DIR}/mat4-test.cc
	${MST_TEST_DIR}/quat-test.cc
	${MST_TEST_DIR}/rectangle-test.cc
	${MST_TEST_DIR}/misc-test.cc)
source_group( test FILES ${TEST_SOURCES} )

# Executable
add_executable( ${PROJECT_NAME}-tests ${TEST_SOURCES} )
target_link_libraries( ${PROJECT_NAME}-tests CONAN_PKG::catch2 ${PROJECT_NAME} )

include( CTest )
include( Catch )
catch_discover_tests( ${PROJECT_NAME}-tests )

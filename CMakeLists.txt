cmake_minimum_required( VERSION 3.15 )
project( mathspot
	VERSION 0.5.1
	DESCRIPTION "C++ math library coded for learning purposes"
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

# Sources
set( SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( SOURCES
	${SOURCE_DIR}/math.cc
	${SOURCE_DIR}/shape.cc
)
source_group( Sources FILES ${SOURCES} )

# Library
add_library( ${PROJECT_NAME} ${SOURCES} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
target_compile_features( ${PROJECT_NAME} PUBLIC cxx_std_17 )

# Test
add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/test )

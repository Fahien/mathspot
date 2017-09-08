cmake_minimum_required(VERSION 3.6)
set(MST_TITLE MathSpoT)
project(${MST_TITLE})

# Version number
set(MST_VERSION_MAJOR 0)
set(MST_VERSION_MINOR 2)
set(MST_NAME mathspot)

# Includes
set(MST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${MST_INCLUDE_DIR})

# Sources
set(MST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES ${MST_SOURCE_DIR}/MathSpot.cpp)
source_group(Sources FILES ${SOURCES})

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 11)

# Library
add_library(${MST_NAME} ${SOURCES})
set_target_properties(${MST_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Test
set(MST_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

function(make_test TEST_NAME)
	# Sources
	set(TEST_SOURCES ${MST_TEST_DIR}/${TEST_NAME}.cpp)
	source_group(${TEST_NAME} FILES ${TEST_SOURCES})

	# Executable
	add_executable(${TEST_NAME} ${TEST_SOURCES})
	set_target_properties(${TEST_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	target_link_libraries(${TEST_NAME} ${MST_NAME})
	add_test(${TEST_NAME} ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
endfunction(make_test)

make_test(size-test)
make_test(vec2-test)
make_test(vec3-test)
make_test(mat4-test)
make_test(rectangle-test)

include(CTest)

cmake_minimum_required( VERSION 3.15 )
project( mathspot
	VERSION 0.5
	LANGUAGES C CXX
)

# Includes
set(MST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# Sources
set(MST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES ${MST_SOURCE_DIR}/math.cc)
source_group(Sources FILES ${SOURCES})

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 17)

# Library
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${MST_INCLUDE_DIR})

# Test
find_package(Catch2 REQUIRED)
set(MST_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# Sources
set(TEST_SOURCES
	${MST_TEST_DIR}/main-test.cc
	${MST_TEST_DIR}/size-test.cc
	${MST_TEST_DIR}/vec2-test.cc
	${MST_TEST_DIR}/vec3-test.cc
	${MST_TEST_DIR}/mat4-test.cc
	${MST_TEST_DIR}/quat-test.cc
	${MST_TEST_DIR}/rectangle-test.cc
	${MST_TEST_DIR}/misc-test.cc)
source_group(test FILES ${TEST_SOURCES})

# Executable
add_executable(${PROJECT_NAME}-tests ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}-tests Catch2::Catch2 ${PROJECT_NAME})

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME}-tests)

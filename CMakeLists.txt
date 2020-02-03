cmake_minimum_required( VERSION 3.15 )
project( mathspot
	VERSION 0.4
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
set(MST_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

function(make_test TEST_NAME)
	# Sources
	set(TEST_SOURCES ${MST_TEST_DIR}/${TEST_NAME}.cpp)
	source_group(${TEST_NAME} FILES ${TEST_SOURCES})

	# Executable
	add_executable(${TEST_NAME} ${TEST_SOURCES})
	target_include_directories(${TEST_NAME} PRIVATE ${MST_INCLUDE_DIR})
	target_link_libraries(${TEST_NAME} ${PROJECT_NAME})
	add_test(${TEST_NAME} ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
endfunction(make_test)

make_test(size-test)
make_test(vec2-test)
make_test(vec3-test)
make_test(mat4-test)
make_test(rectangle-test)
make_test(misc-test)

include(CTest)

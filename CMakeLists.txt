cmake_minimum_required(VERSION 3.0.2)
project(MathSpoT)

# Version number
set(MST_VERSION_MAJOR 0)
set(MST_VERSION_MINOR 1)
set(MST_TITLE "MathSpoT")

set(MST_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(MST_SOURCE_DIR  "${PROJECT_SOURCE_DIR}/src")

# Include dir
include_directories("${MST_INCLUDE_DIR}")

# Sources
set(SOURCES ${MST_SOURCE_DIR}/MathSpot.cpp)
source_group("Sources" FILES ${SOURCES})

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 11)

# Library
add_library(mathspot ${SOURCES})
set_target_properties(mathspot PROPERTIES LINKER_LANGUAGE CXX)

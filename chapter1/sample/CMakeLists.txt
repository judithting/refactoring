cmake_minimum_required(VERSION 3.10)

project(videorental VERSION 1.0.0 LANGUAGES CXX)
message(STATUS "VideoRental Version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

option(VIDEORENTAL_WITH_TESTS "Compile and (for videorental_check) run VideoRental test executables" ON)
option(BUILD_SHARED_LIBS "Build videorental_lib as a shared library." ON)
option(BUILD_STATIC_LIBS "Build videorental_lib as a static library." ON)
option(BUILD_OBJECT_LIBS "Build videorental_lib as a object library." ON)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g -Wall -O2")

configure_file("${PROJECT_SOURCE_DIR}/version.in" "${PROJECT_BINARY_DIR}/version" NEWLINE_STYLE UNIX)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

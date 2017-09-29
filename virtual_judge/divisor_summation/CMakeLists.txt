cmake_minimum_required(VERSION 3.6)
project(oj)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE debug CACHE STRING "build debug")

add_definitions(-W -Wall -DPRINT)

aux_source_directory(./ SOURCE_FILES)

add_executable(target ${SOURCE_FILES})

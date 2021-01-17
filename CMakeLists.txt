cmake_minimum_required(VERSION "3.10")
project(LRSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(GLOB_RECURSE source_files "source/*.cpp" "source/*.h")

add_executable(test ${source_files})
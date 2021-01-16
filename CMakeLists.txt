cmake_minimum_required(VERSION "3.10")
project(LRSystem)

file(GLOB_RECURSE source_files "source/*.cpp" "source/*.h")

add_executable(test ${source_files})
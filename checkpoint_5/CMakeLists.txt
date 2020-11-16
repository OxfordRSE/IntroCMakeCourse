cmake_minimum_required(VERSION 3.15)

project(IntroCMakeCourse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

add_subdirectory(src)
add_subdirectory(exe)

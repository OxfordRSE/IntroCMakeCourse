set(
        cmake_course_source_files
        functionality.cpp
)

set(
        cmake_course_header_files
        functionality.hpp
)

add_library(cmake_course_lib STATIC ${cmake_course_source_files} ${cmake_course_header_files})
target_include_directories(cmake_course_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

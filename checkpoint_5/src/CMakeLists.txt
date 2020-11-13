find_package(Eigen3 CONFIG REQUIRED)
message(STATUS "Found Eigen3 ${Eigen3_VERSION}")

set(
        cmake_course_source_files
        functionality.cpp
        functionality_eigen.cpp
)

set(
        cmake_course_header_files
        functionality.hpp
        functionality_eigen.hpp
)

add_library(cmake_course_lib STATIC ${cmake_course_source_files} ${cmake_course_header_files})
target_include_directories(cmake_course_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cmake_course_lib PRIVATE Eigen3::Eigen)
target_link_libraries(cmake_course_lib PRIVATE project_warnings)

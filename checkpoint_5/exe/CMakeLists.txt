find_package(Boost MODULE REQUIRED COMPONENTS program_options)
message(STATUS "Found Boost ${Boost_VERSION}")

add_executable(main_executable main.cpp)
target_link_libraries(main_executable PRIVATE cmake_course_lib)
target_link_libraries(main_executable PRIVATE project_warnings)
target_link_libraries(main_executable PRIVATE Boost::program_options)

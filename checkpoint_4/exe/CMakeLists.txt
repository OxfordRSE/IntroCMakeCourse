################################################################
# Here you will need to find the Boost program options component
################################################################

add_executable(main_executable main.cpp)
target_link_libraries(main_executable PRIVATE cmake_course_lib)

########################################################################
# Here you will need to link main_executable with Boost::program_options
########################################################################

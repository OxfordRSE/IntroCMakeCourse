set(
        src_source_files
        functionality.cpp
        main.cpp
)

set(
        src_header_files
        functionality.hpp
)

add_executable(main_executable ${src_source_files} ${src_header_files})

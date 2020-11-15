% Introduction to modern CMake
% **Oxford Research Software Engineering**
% Fergus Cooper ~ Graham Lee ~ Thibault Lestang


## CMake has changed a lot

Some words here


## Adding subdirectories

    CMakeLists.txt/
    src/
      CMakeLists.txt
      functionality.cpp
      functionality.hpp
      main.cpp

In top-level `CMakeLists.txt`:

    add_subdirectory(src)

CMake processes file `CMakeLists.txt` in directory `src`.


## Compartmentalize build logic

    # src1/CMakeLists.txt
    set(
      src_source_files
      file1
      file2
      file3
      )
    add_library(component1 ${src_source_files})

Variables defined in callers are available in callee.

Using subdirectories enables modularity.


## Programming CMake

Variables can hold lists:

    set( src_files main.cpp functionality.cpp functionality.hpp )
    
Variables can be dereferenced

    message("src_files = ${src_files}")
	
    "src_files = main.cpp;functionality.cpp;functionality.hpp"


## Programming CMake

Conditionals...

    if(expression)
      # Do something
    else()
      # Do something else
    endif()

and loops:

    set(mylist A B C D)
    foreach(var IN LISTS mylist)
      message(${var})
    endforeach()

## That's all, folks

This was only the tiniest tip of the modern CMake iceberg. There are so many great resources available, and here are just a few of them:

- [The CMake documentation (link)](https://cmake.org/cmake/help/latest/)
- [Professional CMake: A Practical Guide (link)](https://crascit.com/professional-cmake/)
  
Thank you for coming!

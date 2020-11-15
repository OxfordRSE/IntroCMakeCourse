% Introduction to modern CMake
% **Oxford Research Software Engineering**
% Fergus Cooper ~ Graham Lee ~ Thibault Lestang


## CMake has changed a lot

Some words here

## Printing information with ~message()~

    name = "Jane Doe"
    message(STATUS "Hello ${name}")

    -- The C compiler identification is GNU 8.3.0
    ...
    -- Hello Jane Doe
    -- Configuring done
    -- Generating done

## Options for ~message()~

	message(STATUS "A simple message")
	
`STATUS` can be replaced by *e.g.* `WARNING`, `SEND_ERROR`, `FATAL_ERROR` 
depending on the situation.

    message(SEND_ERROR "An error occurred but configure step continues")

    CMake Error at CMakeLists.txt:2 (message):
      An error occurred but configure step continues
    
    -- Configuring incomplete, errors occurred!


## Finding libraries

Libraries can be installed in various locations. On GNU/Linux, typical locations
include `/usr/local/lib`, `/usr/lib/x86_64-linux-gnu` or `~/.local/lib`.

CMake makes it easy to link against libraries without having to know
where they are installed:

    find_package(library_name CONFIG REQUIRED)

The above defines a new target (usually named `library_name`) that can now be linked
against other targets using `target_link_libraries`.


## "config" mode for `find_package`

-   In "config mode", `find_package` will search for a
    `<PackageName>Config.cmake` file.
-   This file specifies all the information CMake needs (particularly where
    the library is installed).
-   This is usually given by the library vendor.


## Checkpoint 3

A new file `src/functionality_eigen.cpp` depends on the [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)
library for linear algebra.

Task: Using `find_package`, modify the `CMakeLists.txt` in directory `src/` to
link target `cmake_course_lib` against Eigen.
Useful instructions can be found at [Using Eigen in CMake Projects](http://eigen.tuxfamily.org/dox/TopicCMakeGuide.html).

*Note that keyword `NO_MODULE` is equivalent to `CONFIG`*

## That's all, folks

This was only the tiniest tip of the modern CMake iceberg. There are so many great resources available, and here are just a few of them:

- [The CMake documentation (link)](https://cmake.org/cmake/help/latest/)
- [Professional CMake: A Practical Guide (link)](https://crascit.com/professional-cmake/)
  
Thank you for coming!

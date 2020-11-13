# Oxford RSE: Introduction to CMake

An introductory course in CMake from Oxford RSE.

## [Checkpoint 0](./checkpoint_0)

This checkpoint contains a single `CMakeLists.txt` file and a single `main.cpp` file.

Concepts introduced:

- Setting a minimum CMake version with the CMake `cmake_minimum_required` command
- Defining project name and languages with the CMake `project` command
- Setting variables using the CMake `set` command
- Setting the C++ language standard with the CMake `CMAKE_CXX_STANDARD` variable
- Defining an executable with the CMake `add_executable` command

Discussion points:

- Basic configure-build-run cycle:
  ```bash
  mkdir build && cd build
  cmake ..
  make main_executable
  ./main_executable
  ```
- Choosing a generator:
  ```bash
  cmake -G Ninja ..
  ```
- Build uniformly regardless of generator:
  ```bash
  cmake --build . --target main_executable
  ```
- Configure to compile in Release mode:
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Release ..
  ```


## [Checkpoint 1](./checkpoint_1)

This checkpoint contains two `CMakeLists.txt` files, one in the top level directory and one in the subdirectory `src`.
There are now there source files: `main.cpp`, and two files `functionality.hpp` and `functionality.cpp`.
These provide a method called in `main.cpp`.

Concepts introduced:

- Including a `CMakeLists.txt` in a subdirectory using the CMake `add_subdirectory` command
- Add modularity to a CMake project by defining logic only in relevant directories
- Setting lists of variables using the CMake `set` command
- Dereferencing CMake variables using the CMake `${var_name}` syntax


## [Checkpoint 2](./checkpoint_2)

This checkpoint separates the functionality from the executable by creating a library, that will be built and linked with the executable.
There are now three `CMakeLists.txt` files: one in the top level directory, one in `src` and one in `exe`.

Concepts introduced:

- Defining a library with the CMake `add_library` command
- Specifying the library's include directories with the CMake `target_include_directories` command
- Identifying the current directory during project generation with the `CMAKE_CURRENT_SOURCE_DIR` variable
- Specifying a library to link using the CMake `target_link_libraries` command


## [Checkpoint 3](./checkpoint_3)

This checkpoint adds a project dependency: Eigen.
The library `cmake_course_lib` now requires linear algebra functionality, and we use CMake to find Eigen.

Concepts introduced:

- Finding a dependency in "config mode" using the CMake `find_package` command
- Printing information using the CMake `message` command

Discussion points:

- In "config mode", `find_pacakge` will search for a `<PackageName>Config.cmake` file, provided by the library vendor,
 that specifies all information necessary to use the library.


## [Checkpoint 4](./checkpoint_4)

This checkpoint adds a project dependency: Boost.
The executable `main_executable` now requires boost program options, which we find with CMake.

Concepts introduced:

- Finding a dependency in "module mode" using the CMake `find_package` command

Discussion points:

- In "module mode", `find_pacakge` will execute instructions in a `Find<PackageName>.cmake` file.
 For a number of common libraries, this file is [provided with CMake](https://cmake.org/cmake/help/latest/module/FindBoost.html),
 but can also be written as required.


## [Checkpoint 5](./checkpoint_5)

This checkpoint adds a configurable list of compiler warnings.

Concepts introduced:

- Including additional CMake functionality using the CMake `include` command
- Creating an interface "library" just for the purpose of applying options to other targets
- Defining a function using the CMake `function` keyword
- Defining a configure-time option using the CMake `option` command
- Using conditionals with the CMake `if`, `else` and `elseif` keywords
- Identifying the compiler using the CMake `CMAKE_CXX_COMPILER_ID` variable

Discussion points:

- Specifying options at configure-time:
  ```bash
  cmake -DWARNINGS_AS_ERRORS=FALSE ..
  ```

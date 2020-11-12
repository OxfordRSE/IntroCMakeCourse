# Oxford RSE: Introduction to CMake

An introductory course in CMake from Oxford RSE.

## [Checkpoint 0](./checkpoint_0)

This checkpoint contains a single `CMakeLists.txt` file and a single `main.cpp` file.

Concepts introduced:

- Setting a minimum CMake version with the CMake `cmake_minimum_required` command
- Defining project name and languages with the CMake `project` command
- Setting variables using the CMake `set` command
- Setting the C++ language standard with the CMake `CMAKE_CXX_STANDARD` variable

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


## [Checkpoint 1](./checkpoint_1)

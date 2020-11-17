% Introduction to modern CMake
% **Oxford Research Software Engineering**
% Fergus Cooper ~ Graham Lee ~ Thibault Lestang

# Problem Statement

You want your C++ code to compile on other computers, not just your laptop.

 - group workstation
 - HPC compile node
 - collaborator laptops

Everyone should end up with a program that behaves the same way, wherever they build.

# Enter CMake

You describe _targets_ (what to build), _inputs_ (the sources files), and _configuration_ (what libraries to use, what compiler settings, etc.).

CMake uses that with its own _rules_ (how to turn sources into programs) to generate makefiles, IDE projects, or other outputs. CMake doesn't build your project itself!

CMake works on Linux, Windows, macOS and more.

# Getting Started

Checkpoint 0 is a simple "hello, world" program written in C++. Let's use CMake to build it.

```
$ cd checkpoint_0
```

# `CMakeLists.txt`

This is where you write the definitions of your targets and configuration.

Let's look at the sample `CMakeLists.txt` line by line.

# CMake has changed a lot

```
cmake_minimum_required(VERSION 3.15)
```

Tells CMake which version we used, affecting the features available and the interpretation of `CMakeLists.txt`

# Define a project

```
project(IntroCMakeCourse LANGUAGES CXX)
```

We have a project called `IntroCMakeCourse`, in the C++ language.

# Configure the compiler

```
set(CMAKE_CXX_STANDARD 17)
```

We're using the C++17 language dialect.

# Tell it what to build

```
add_executable(main_executable main.cpp)
```

There is a program, called `main_executable`, which depends on the source code in `main.cpp`

# Using CMake

It's typical to build "out of tree", by running CMake in a separate place. Keeps generated files out of your source folder.

```
checkpoint0$ mkdir build
checkpoint0$ cd build
build$ cmake ..
[...]
-- Build files have been written to: /Users/gralee/OxfordRSE/IntroCMakeCourse/checkpoint_0/build
```

# Build your project

CMake only generated the build script, it didn't actually compile anything.

```
build$ make
[...]
[100%] Built target main_executable
build$ ./main_executable 
Checkpoint 0
Hello, World!
```

# Choosing a generator

CMake can create more than Makefiles. It can generate IDE projects, or build descriptions for the fast Ninja tool.

```
build$ cmake -G Ninja ..
[...]

build$ ninja
[2/2] Linking CXX executable main_executable
```
# Setting configuration

You (and users) can override choices made by CMake using the `-D` argument.

```
build$ cmake -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-10 ..
-- Configuring done
You have changed variables that require your cache to be deleted.
Configure will be re-run and you may have to reset some variables.
The following variables have changed:
CMAKE_CXX_COMPILER= /usr/local/bin/g++-10

-- The CXX compiler identification is GNU 10.2.0
[...]
```

# Adding CMake functionality using `include`

Any file containing valid CMake syntax can be "included" in the
current `CMakeLists.txt`:

    # CMakeLists.txt
    cmake_minimum_required(VERSION 3.13)
    project(IntroCMakeCourse LANGUAGES CXX)
    include(to_include.cmake)
    
    set(name "Foo Bar")
    message(STATUS "Hello ${name}")

    # cmake/file_to_include.cmake
    set(name "Jane Doe")
    message(STATUS "Hello ${name}")

    -- Hello Jane Doe
    -- Hello Foo Bar
    -- Configuring done
    ...


# Programming CMake: functions

CMake allows the declaration of functions:

    function(add a b)
      math(EXPR result "{a}+{b}")
      message("The sum is ${result}")
    endfunction()

Functions cannot return a value.

Functions introduce a new scope.

A similar notion is CMake *macros*, which does **not** introduce a new scope.


# Setting options with `option()`

Boolean variables can be declared using `option()`:

    option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" TRUE)

The value of options can be specified at the command line using the
`-D` syntax:

    cmake -DWARNINGS_AS_ERRORS=FALSE ..

Options are a special case of "cache" variable, which value persist
between CMake runs.


# Built-in CMake variables

CMake provides *a lot* of pre-defined variables which values describe the system.

For instance, the value of `CMAKE_CXX_COMPILER_ID`' can be queried
to determine which C++ compiler is used.

    if(MSVC)
        set(PROJECT_WARNINGS ${MSVC_WARNINGS})
      elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        set(PROJECT_WARNINGS ${CLANG_WARNINGS})
      elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(PROJECT_WARNINGS ${GCC_WARNINGS})
      else()
        # ...


# Using an interface "library" to apply options across targets

TODO

# That's all, folks

This was only the tiniest tip of the modern CMake iceberg. There are so many great resources available, and here are just a few of them:

- [The CMake documentation (link)](https://cmake.org/cmake/help/latest/)
- [Professional CMake: A Practical Guide (link)](https://crascit.com/professional-cmake/)
  
Thank you for coming!

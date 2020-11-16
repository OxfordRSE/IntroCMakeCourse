% Introduction to modern CMake
% **Oxford Research Software Engineering**
% Fergus Cooper ~ Graham Lee ~ Thibault Lestang


## CMake has changed a lot

Some words here

## Target properties

CMake allows for a very fine-grained control of target builds, through
*properties*.

For example, the property `INCLUDE_DIRECTORIES` specifies the list of
directories to be specified with the compiler switch `-I` (or `/I`).

Properties can be set manually like variables, but in general CMake provides
commands for it:

    target_include_directories(main_executable
		                       PRIVATE
							   ${CMAKE_CURRENT_SOURCE_DIR}
	)

*Properties are different from variables!*


## Creating a library

Similar to `add_executable()`:

    add_library(my_lib STATIC ${source_files})

Use ~SHARED~ instead of ~STATIC~ to build a shared library.


## Linking libraries (`PRIVATE`)

Library dependencies can be declared using the `target_link_libraries()` command:

    target_link_libraries(another_lib PRIVATE my_lib)

The `PRIVATE` keyword states that `another_lib` uses `my_lib` in its internal
implementation. Programs using `another_lib` don't need to know about `my_lib`.


## Linking libraries (`PUBLIC`)

Picture another dependency scenario:

-   `another_lib` uses `my_lib` in its internal implementation.
-   **and** `another_lib` defines some function that take parameters of a type defined
    in `my_lib`.

Programs using `another_lib` also must link against `my_lib`:

    target_link_libraries(another_lib PUBLIC my_lib)


## Link libraries (`INTERFACE`)

Picture another dependency scenario:

- `my_lib` only uses `my_lib` in its interface.
- **but not** in its internal implementation.

```
target_link_libraries(another_lib INTERFACE my_lib)
```

## Behaviour of target properties across dependencies

Many (**all?**) target properties are paired with another property
`INTERFACE_<PROPERTY>`. For instance

    INTERFACE_INCLUDE_DIRECTORIES

These properties are inherited by depending targets (such as
executables and other libraries).

Example:

    target_include_directories(my_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

-   `PRIVATE`: sets `INCLUDE_DIRECTORIES`.
-   `INTERFACE`: sets `INTERFACE_INCLUDE_DIRECTORIES`.
-   `PUBLIC`: sets both.

## That's all, folks

This was only the tiniest tip of the modern CMake iceberg. There are so many great resources available, and here are just a few of them:

- [The CMake documentation (link)](https://cmake.org/cmake/help/latest/)
- [Professional CMake: A Practical Guide (link)](https://crascit.com/professional-cmake/)

Thank you for coming!

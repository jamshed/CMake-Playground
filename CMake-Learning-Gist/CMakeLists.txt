# Specify the minimum version of CMake to use.
# CMake can have different behaviors (policies) based on its version used.
cmake_minimum_required(VERSION 3.14)


# Name the project, its version, and languages used in it.
project(cmake_learning_gist
        VERSION 0.1.0
        LANGUAGES C CXX
    )


# Fix language standards, and set hard requirements for such.
# All targets defined from this point onward will pick up these requirements.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIED ON)


# Just printing out the project root directory (a sanity check may be?).
message("Project root: " ${CMAKE_SOURCE_DIR})


# The `Debug` configuration optimizes the program for debugging and enables full debug information.
# The `Release` configuration enables most compiler optimizations for speed and defines `NDEBUG`
# (No Debug) which will remove all traces of the standard library assert calls.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()


# Add subdirectory `src` to the build; CMake will open `src/CMakeLists.txt` for such.
add_subdirectory(src)

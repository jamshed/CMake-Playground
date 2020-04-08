cmake_minimum_required(VERSION 3.10)

# Set the project name
project(hello_cmake VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Configure a header file to pass the project version number to the source code
configure_file(Hello_CMake_Config.h.in Hello_CMake_Config.h)

# Add the executable
add_executable(hello_cmake hello_cmake.cxx)

# The configuration file will be written into the project directory, so add
# the directory to the list of paths to search for include files.
target_include_directories(hello_cmake PUBLIC
                            "${PROJECT_BINARY_DIR}"
                        )
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(hello_cmake VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Make use of the MathFunctions library optional
option(USE_MYMATH "Use the custom math library implementation" ON)

# Configure a header file to pass some CMake settings to the source code
configure_file(Hello_CMake_Config.h.in Hello_CMake_Config.h)

# If the `USE_MYMATH` option is found `ON`, then add the `MathFunctions`
# library to the `EXTRA_LIBS` list, and add the corresponding sources to
# the `EXTRA_INCLUDES` list
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# Add the executable
add_executable(hello_cmake hello_cmake.cxx)

target_link_libraries(hello_cmake PUBLIC ${EXTRA_LIBS})

# The configuration file will be written into the project binary directory,
# so add the directory to the list of paths to search for include files.
target_include_directories(hello_cmake PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${EXTRA_INCLUDES}"
                        )
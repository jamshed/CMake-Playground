# In CMake, usually an executable or a library is referred to as a 'target'.
# Roughly, my basic CMake design flow usually looks like this:
# 1.    build libraries using `add_library`;
# 2.    specify the directories to be included in the target libraries by `target_include_directories`;
# 3.    create an executable for the project using `add_executable`;
# 4.    (optional) use `target_include_directories` for the target executable; it is optional
#   if the libraries to be linked later to the exectuable had used the `PUBLIC` propagation policy
#   in their `target_include_directories` invocation;
# 5.    link the built libraries to the exectuable using `target_link_libraries`.


# Bundle the core source files into a variable.
set(PROJECT_SRC
        greeter/greet.cpp
        factorial/factorial.c
)


# Build a library with the provided source(s).
# `STATIC` will force the creation of a static library (and so no runtime linking).
add_library(core STATIC ${PROJECT_SRC})


# This controls the `-I` (include paths) switch of the compiler invocation.
# Since `include` is declared `PUBLIC` for the library, it is propagated to all the
# consumers of the library.
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)


# Specify various flags to the compiler for the target library. As the flags are specified as
# `PRIVATE`, they will only be used when compiling this library. The flags will not be propagated to
# the targets linking to it.
target_compile_options(core PRIVATE ${WARNING_FLAGS} ${SUPPRESS_WARNING_FLAGS} ${OPTIMIZE_FLAGS})

# Optionally provide flags for debug-info symbols.
if(DEBUG_INFO)
    target_compile_options(core PRIVATE ${DEBUG_FLAGS})
endif()


# Create an executable from the driver program.
add_executable(${PROJECT_NAME} main.cpp)


# Link the core library to other required libraries, e.g. the threads library.
target_link_libraries(core PRIVATE Threads::Threads)

# Link the executable to the required libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE core)


# Specify various flags to the compiler for the target library.
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS} ${SUPPRESS_WARNING_FLAGS} ${OPTIMIZE_FLAGS})


# Set the parent directory for the target binaries as `bin` directory inside the "installation directory".
# The installation directory is set to `/usr/local` by default. Installing softwares there ensures that
# those are automatically available to users. You may need root access (use `sudo`) for such.
# To specify a different parent installation directory, pass the directory as the value of the
# `-DCMAKE_INSTALL_PREFIX` with the `cmake` command.

set(DEFAULT_INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin)        # Set our default installation directory as a `bin` directory inside the top level of the source tree.
set(INSTALL_DIR .)      # Set the installation directory to what CMake has recieved, i.e. either the system default or the user-provided one.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT) # If it's set to the system default, then set it to our defined default directory.
        set(INSTALL_DIR ${DEFAULT_INSTALL_DIR})
endif()

install(TARGETS ${PROJECT_NAME}
        DESTINATION ${INSTALL_DIR}
        )

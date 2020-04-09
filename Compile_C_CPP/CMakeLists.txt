# Name the project and languages used.
project(hello LANGUAGES C)


# Create an executable program named `main` from the specified source(s).
# add_executable(hello include/header.h src/source.c)

# A better approach:
set(INCLUDES include/header.h)
set(SOURCES src/source.c)
add_executable(main ${INCLUDES} ${SOURCES})


# This controls the `-I` (include paths) switch of the compiler invocation.
target_include_directories(main PRIVATE include)
# NB: Not clear on `PRIVATE` vs. `PUBLIC` vs. `INTERFACE`.


# Select a language standard, and set a hard requirement for such if required.
set_target_properties(main PROPERTIES
                      C_STANDARD 11
                      C_STANDARD_REQUIRED ON)
# set_target_properties(main PROPERTIES
#                       CXX_STANDARD 14
#                       CXX_STANDARD_REQUIRED ON)
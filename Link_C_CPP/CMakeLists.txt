# Name the project and languages used.
project(factorial LANGUAGES CXX)


# Build a library with the provided source(s).
set(LIB
    src/greet.cpp
    src/factorial.cpp
    )
add_library(lib STATIC ${LIB})
# ``STATIC`` will force the creation of a static library.


# This controls the `-I` (include paths) switch of the compiler invocation.
target_include_directories(lib PUBLIC include)


# Create an executable program named `main` from the specified source(s).
add_executable(main src/main.cpp)

# Note that, we do not need to redeclare the include directory of the library
# `lib` for the target `main` again using a `target_include_directories`.
# Since `include` is declared `PUBLIC` for `lib`, it is propagated to all the
# consumers of `lib`, and so to `main`.


# Link the library `lib` to the target `main`.
target_link_libraries(main PRIVATE lib)

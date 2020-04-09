```
# Out-of-source compilation directory
$ mkdir build
$ cd build

# Run the `CMakeLists.txt` from the parent directory.
$ cmake ..

# Call the generated build system to execute the produced makefiles.
$ cmake --build .

# Verbose makefiles print out every command executed by the build system,
# and as such, is an excellent CMake debugging option.
$ cmake --build . -- VERBOSE=1
```

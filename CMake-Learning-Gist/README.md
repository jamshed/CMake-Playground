### Build an out-of-source compilation directory:
```
$ mkdir build
$ cd build
```

### Running the `CMakeLists.txt` from the parent directory:
  - To build with default build configurations and have the final executable inside `<project-dir>/build/src/`:
```
$ cmake ..
```

  - To use `Release` / `Debug` build configuration, set the value of the `CMAKE_BUILD_TYPE` variable with the `-D` parameter:
```
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
```
If nothing is provided, the default is set to `Release` in the `CMakeLists.txt`.

  - To specify a custom install location for the executable, set the value of the `CMAKE_INSTALL_PREFIX` variable with
  the `-D` parameter:
```
$ cmake -DCMAKE_INSTALL_PREFIX=../ ..
```
This will set the installation parent directory as the project directory (`..` from `build`), and install the executable
inside a `bin` directory there. This `bin` directory is set in the `src/CMakeLists.txt`.

An example invocation:
```
$ cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../ ..
```

### Call the generated build system to execute the produced makefiles:
```
$ cmake --build .
```
Or,
```
$ make
```
Both of these will produce the executable named `main` at `<project-dir>/build/src/`. To install the executable at
`<project-dir/bin/`:
```
$ make install
```
If the executable is to be installed at `/usr/local/bin` and thus made available to all the users, do not pass anything
as the value of the `CMAKE_INSTALL_PREFIX` variable with the `cmake` command. Then a `make install` (or `sudo make install` if root
access is required) will install the executable there.

### To sum up
A typical execution flow might be similar to this from the `<project-dir>`:
```
$ mkdir build
$ cd build

$ cmake -DCMAKE_INSTALL_PREFIX=../ ..

$ make install
```

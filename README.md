# CAPD example application with built-in library component

An example CAPD-based project that is built together with CAPD library.

## Getting started

In order to perform the build it is necessary to have `git`, `cmake` and `make` tools installed as well as C++ compiler with C++17 support.

In order to set up and run the example it is necessary to perform the following commands.

1. Clone this repository:

        git clone https://github.com/CAPDGroup/CAPD.example.2

2. Perform build (script `build.sh` performs submodule update, repository configuration and the build itself):

        cd CAPD.example.2
        ./build.sh

3. Run the application:

        cd build
        ./capd_example

The commands above will build an example executable together with CAPD library.

In order to repeat the build (e.g. after introducing changes in the source code), `build.sh` should not be called. It is sufficient to do:

    cd build
    make


# CAPD example application with built-in library component

An example CAPD-based project that is built together with CAPD library.

## Getting started

In order to perform the build it is necessary to have `git`, `cmake` and `make` tools installed as well as C++ compiler with C++17 support.

In order to set up and run the example it is necessary to perform the following commands.

1. Clone this repository:

        git clone https://github.com/CAPDGroup/CAPD_example_standalone

1. Perform the build:

        cd CAPD_example_standalone
        git submodule update --init --recursive
        mkdir build
        cd build
        cmake ..
        make

1. Run the application:

        ./capd_example

The commands above will build an example executable together with CAPD library.

In order to repeat the build (e.g. after introducing changes in the source code), it is sufficient to call:

    make

from the `build` directory.

# CAPD example application with built-in library component
## Overview
An example application demonstrating how to build cmake application together with CAPD library.

## Getting started
1. Clone the repository:

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

The build can be made faster by replacing `make` command with `make -j <n>`, where `<n>` is the number of parallel jobs, e.g. `make -j 4`.

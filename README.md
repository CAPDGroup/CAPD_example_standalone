# CAPD example application (2)
## Overview
Mini-project demonstrating how to build cmake application that is built together with CAPD library.

## Getting started
Clone the repository:

    git clone https://github.com/CAPDGroup/CAPD.example.2
    
Enter the repository, create the build folder, configure the repository and then build:

    cd CAPD.example.2
    git submodule update --init --recursive
    mkdir build
    cd build
    cmake ..
    make

The commands above will build an example executable together with CAPD library.

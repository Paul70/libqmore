# libqmore, shared C++/Qt library containing non-standard Qt widget classes

## Development

At the moment, libqmore can be built using a number of toolchains:

* gcc: Uses an Ubuntu 20.04.2 LTS Linux machine with the gcc compiler
* clang: Uses an Ubuntu 20.04.2 LTS Linux machine with the clange compiler

Support for the following toolchain will be available soon:

* mingw_native: This uses the MSYS2 software packages to build native windows packages (.exe and .dll) on a Windows host.

Currently, support for msvc is under investigation.

The project libqmore supports cmake as build system.
This library was developed using Qt Creator as IDE. I did not test other IDEs which support cmake.


## Installation and Usage

A installation of the Qt package is mandatory. If you do not already have Qt installed on your machine go to

    https://www.qt.io/
    
and install Qt. If you do not have cmake install cmake.
Clone the repository from Github. Open the top level CMakeLists.txt, run cmake and build the project.
Currently, it is sometimes necesarry to run cmake several times when building the project for the first time. I will fix this bug 
soon.
Run the example executables to get a basic usage exmaple and to see what functionality the widgets offer.

When using the clang toolchain I had to install the following packages manually:
* $ sudp apt-get install qtbase5-dev
* $ sudp apt-get install qtdeclarative5-dev
* $ sudp apt-get install qttools5-dev


## Widgets

- FloatSlider

- LedIndicator


## CMake options
explanation will follow soon

## Headertest
explanation will follow soon




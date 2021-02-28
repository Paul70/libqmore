cmake_minimum_required(VERSION 3.1)

if(NOT PROJECT_NAME)
    project(libqmore
        VERSION 0.0
        DESCRIPTION "Shared Qt/C++ library containing non-standard Qt classes and widgets"
        LANGUAGES C CXX)
endif()

# include CMakemodules directories
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
include(QMoreHeaderTesting)
include(QMoreProjectSettings)

# set build options
option(LIBQMORE_BUILD_HEADER_TEST "Test all libqmore C++ headers using a stand-alone main" ON)
option(LIBQMORE_BUILD_TESTS "Build Google Tests test suite" ON)
option(LIBQMORE_BUILD_EXAMPLES "Build libqmore examples" ON)

# add shared library qmorewidgets
add_subdirectory(libqmorewidgets)

# add optional targets
if(LIBQMORE_BUILD_TESTS)
    add_subdirectory(thirdparty/googletest)
    add_subdirectory(libqmoretests)
endif()
if(LIBQMORE_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

# Add a dummy non-built target to make Qt Creator IDE list additional files
add_custom_target(extra SOURCES README.md)

# Add header tests (this code must always come last so that  it can pick up all headers up to this point)
if(LIBQMORE_BUILD_HEADER_TEST)
    add_subdirectory(headertest)
endif()

cmake_minimum_required(VERSION 3.1)


if(NOT PROJECT_NAME)
    project(libqmore
        VERSION 0.0
        DESCRIPTION "Shared library containing non-standard Qt classes and widgets"
        LANGUAGES C CXX)
endif()


# include CMakemodules directories
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
include(QMoreProjectSettings)

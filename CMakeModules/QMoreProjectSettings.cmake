# *******************************************************************************************************************************
# QtWidgetsProjectSettings
#
# This file contains all global project settings and defines useful variables for CMake
#
# *******************************************************************************************************************************

# Guard against multiple includes
if(QMORE_TOOLCHAIN)
    return()
endif()


# Recommanded global settings for projects based on C/C++ (a C++17 compiler is mandatory!)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Define our global W_TOOLCHAIN variable on which we
# base all further build decisions. The variable W_TOOLCHAIN
# is also available as a C/C++ preprocessor macro for
# code, although it should only be used as a last resort there.
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(QMORE_TOOLCHAIN QMORE_MSVC)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(WIN32)
        set(QMORE_TOOLCHAIN QMORE_MINGW_NATIVE)
    else()
        set(QMORE_TOOLCHAIN QMORE_GCC)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(QMORE_TOOLCHAIN QMORE_CLANG)
endif()
add_definitions(-D${QMORE_TOOLCHAIN})


# Add global package QT
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui LinguistTools REQUIRED)

set(W_USE_QT 5 CACHE STRING "Build optional components for given Qt version")
set_property(CACHE W_USE_QT PROPERTY STRINGS 0 4 5)

if(W_USE_QT STREQUAL "4")
   message(AUTHOR_WARNING "Qt 4 is obsolete and not likely to be fully supported anymore.")
endif()

# set the Qt language
set(TS_FILES libqmore_en_US.ts)

# This is a useless variable introduced by Qt Creator.
# Unsetting this removes warnings while cmake runs.
unset(QT_QMAKE_EXECUTABLE)





# compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -O2")




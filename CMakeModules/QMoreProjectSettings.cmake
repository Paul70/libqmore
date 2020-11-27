# *******************************************************************************************************************************
# QtWidgetsProjectSettings
#
# This file contents all global project settings and defines useful variables for CMake
#
# *******************************************************************************************************************************



# Recommanded global settings for projects based on C/C++ (a C++17 compiler is mandatory!)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# find Qt package
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui LinguistTools REQUIRED)


# set the projects's language
set(TS_FILES libqtwidgets_en_US.ts)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -O2")




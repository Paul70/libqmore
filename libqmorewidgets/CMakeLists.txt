add_library(qmorewidgets SHARED
  floatslider.cpp

  floatslider.h
  qmorewidgets_global.h

  ${CMAKE_SOURCE_DIR}/${TS_FILES}
)

target_include_directories(qmorewidgets PRIVATE ..)

target_link_libraries(qmorewidgets PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(qmorewidgets PRIVATE QMOREWIDGETS_LIBRARY)

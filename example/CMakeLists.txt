add_executable(Sliders
  Sliders/main.cpp
  Sliders/mainwindow.cpp

  ${TS_FILES}
)

target_include_directories(Sliders PRIVATE ..)
target_link_libraries(Sliders PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                              PUBLIC  qmorewidgets)

add_executable(LedLights
  LedLights/main.cpp
  LedLights/mainwindow.cpp

  ${TS_FILES}
)

target_include_directories(LedLights PRIVATE ..)
target_link_libraries(LedLights PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                PUBLIC  qmorewidgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

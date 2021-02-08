add_executable(qmoretests
    floatslidertest.cpp
    ledindicatortest.cpp
    main.cpp
)

# Include paths
target_include_directories(qmoretests PRIVATE ..)

# Internal library dependencies - link against the static lib we want to test
target_link_libraries(qmoretests PRIVATE qmorewidgets)

# External library dependencies
target_link_libraries(qmoretests PUBLIC gmock)
target_link_libraries(qmoretests PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_compile_definitions(qmoretests PRIVATE LIBQMOREWIDGETS_LIBRARY)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

# Register all tests
include(GoogleTest)
gtest_add_tests(TARGET qmoretests)

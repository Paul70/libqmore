message("Generating code for header test for project libqmore")
get_property(subdirs_list
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
    PROPERTY SUBDIRECTORIES
)

headerTest(${subdirs_list})

# *******************************************************************************************************************************
# QMoreHeaderTesting
#
# CMake function defintion "headerTest"
# ARGV : a list of all subdirectories of project libqmore (added with add_subdirectory)
#
# 'headerTest' verifies that all project's header files are self-contained, i.e each header file compiles itself or, in other
# words, a cpp file only including a single hader file compiles.
#
# This follows directly the device given on
# https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rs-contained
#
# *******************************************************************************************************************************

function(headerTest)
    message(STATUS "Examining subdirectories: ${ARGV}")

    # loop through all (master)project subdirectories
    foreach(subdir ${ARGV})

        # the subdirectory "headertest" only calls this cmake function
        if(${subdir} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
            continue()
        endif()

        message(STATUS "Examining subdirectory: ${subdir}")

        # get list of all subdirectory targets
        get_property(target_list
            DIRECTORY "${subdir}"
            PROPERTY BUILDSYSTEM_TARGETS
        )
        message(STATUS "examining built targets: ${targets_list} in subdir ${subdir}")

        foreach(target ${target_list})
            message("   exmaning target: ${target}")

            # get the target's type (executable, shared lib, static lib,...)
            get_property(target_type
                TARGET ${target}
                PROPERTY TYPE
            )
            if(${target_type} MATCHES "_LIBRARY$" OR ${target_type} STREQUAL "EXECUTABLE")
                message(STATUS "  target type is: ${target_type}")

                # get the targets's sources
                get_property(target_sources
                    TARGET ${target}
                    PROPERTY SOURCES
                )

                foreach(source ${target_sources})
                    if(${source} MATCHES ".h")
                        continue()
                    endif()
                    message(STATUS "   examining source ${source}")

                    # read out all full header file paths (i.e. /../../../<header_name>.h) for each source file
                    get_filename_component(intermediate_source_path ${source} DIRECTORY)
                    get_filename_component(source_name_we ${source} NAME_WE)
                    #set(header "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/${intermediate_source_path}/${source_name_we}.h")
                    set(header "${subdir}/${intermediate_source_path}${source_name_we}.h")

                    # now, look for exactly this header in the project
                    message(STATUS "   looking for ${header}")
                    if(EXISTS ${header})
                        message(STATUS "   identified ${header}")

                        # setup the header test source file (.cpp), i.e. the little main() programme including only
                        # the current header, in the project's binary directory
                        file(RELATIVE_PATH relative_header_path ${CMAKE_CURRENT_SOURCE_DIR}/.. ${header})
                        get_filename_component(relative_header_path ${relative_header_path} DIRECTORY)

                        message(STATUS "   relative path from top level source directory is ${relative_header_path}")
                        set(header_test_source_file ${CMAKE_CURRENT_BINARY_DIR}/${relative_header_path}/main_${source_name_we}.cpp)

                        # create the cmake target corresponding to this main()-test programme
                        set(header_test_target header_test_${relative_header_path}_${source_name_we})
                        string(REPLACE "/" "_" header_test_target ${header_test_target})

                        # if the target already exists comtinue lopp with next source file
                        if(TARGET header_test_target)
                            continue()
                        endif()

                        # else create file, include directories and link against libraries if neccessary
                        message(STATUS "   Generating output file ${header_test_source_file}")
                        file(GENERATE OUTPUT ${header_test_source_file}
                             CONTENT "#include \"${header}\"\nint main()\n{\nreturn(0);\n}")

                        # For some reason (older cmake?) we are not allowed to create an
                        # object library with other libs linking to it under Linux toolchains.
                        if(QMORE_TOOLCHAIN STREQUAL QMORE_MSVC OR QMORE_TOOLCHAIN STREQUAL QMORE_MINGW_NATIVE)
                            add_library(${header_test_target} OBJECT ${header_test_source_file})
                        else()
                            add_library(${header_test_target} STATIC ${header_test_source_file})
                        endif()

                        # set include directories and link the newly created library target
                        get_property(header_test_target_include_directories
                            TARGET ${target}
                            PROPERTY INCLUDE_DIRECTORIES
                        )
                        message(STATUS "   providing include directories ${header_test_target_include_directories}")
                        target_include_directories(${header_test_target} PRIVATE ${header_test_target_include_directories})

                        get_property(header_test_target_link_libraries
                            TARGET ${target}
                            PROPERTY LINK_LIBRARIES
                        )
                        message(STATUS "   providing link libraries ${header_test_target_link_libraries}")
                        target_link_libraries(${header_test_target} PRIVATE ${header_test_target_link_libraries})

                        # put the compiled output files in the right binary directory
                        set_target_properties(${header_test_target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${relative_header_path})
                    else()
                        message(STATUS "   could not find ${header}")
                    endif()
                endforeach()
            endif()
        endforeach()
    endforeach()
endfunction()

















cmake_minimum_required(VERSION 3.16)
project(scratch) # scratch = main.cpp


##########  Add GTest, GMock as subprojects #################33333333
# Download and unpack googletest at configure time
configure_file(CMakeLists.GTest.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
    include_directories("${gmock_SOURCE_DIR}/include")
endif()

# I should not have to do this, but it was not finding the gtest,gmock headers.
# Reference 1: https://github.com/google/googletest/blob/master/googletest/README.md
# Reference 2: https://crascit.com/2015/07/25/cmake-gtest/
include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${gmock_SOURCE_DIR}/include")

message("Gtest_Source_Dir is: " "${gtest_SOURCE_DIR}")
message("Gtest_Source_Dir is: " "${gmock_SOURCE_DIR}")

################ End Add GTest, GMock ###################

# Sub projects that have a main
add_subdirectory(BackInserter)
add_subdirectory(UniquePointer)
add_subdirectory(SharedPointer)

# static libs
add_subdirectory(libEntity)
add_subdirectory(libMediaAssets)
message("Message test")

# tests
add_subdirectory(tests)

# the top level main
add_executable(scratch main.cpp)

# if main uses a lib, you must add it here
target_link_libraries(scratch libMediaAssets)



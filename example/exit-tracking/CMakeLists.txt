cmake_minimum_required (VERSION 2.6)
project (AppExitTracking CXX)


set (CMAKE_BUILD_TYPE "Release")
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic -ggdb -std=c++98")

set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file (GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

set (EXIT_APP "exit_app")
add_executable (${EXIT_APP} ${SRC_FILES})
target_link_libraries ("${EXIT_APP}" "curl" "qmonix")

add_subdirectory ("lib/qmonix")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/lib/qmonix/include")

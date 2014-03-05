cmake_minimum_required (VERSION 2.6)
project (QmonixClient CXX)


message (STATUS "Build type: ${CMAKE_BUILD_TYPE}.")


if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	add_definitions ("-DQMONIX_BUILD_DEBUG=1")
else()
	add_definitions ("-DQMONIX_BUILD_RELEASE=1")
endif()


set (CMAKE_CXX_FLAGS_DEBUG "-ggdb -std=c++11")
set (CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++98")
set (CMAKE_CXX_FLAGS_TESTCOVERAGE
	"${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fprofile-arcs -ftest-coverage")

set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")

set (CMAKE_EXE_LINKER_FLAGS_TESTCOVERAGE "-fprofile-arcs -ftest-coverage")


set (QMONIX_LIB "qmonix")
set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

file (GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

add_library (${QMONIX_LIB} STATIC ${SRC_FILES})
target_link_libraries ("${QMONIX_LIB}" "curl")


#
# Testing rules.
#


enable_testing()


set (TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
file (GLOB_RECURSE TEST_SRC_FILES "${TEST_SRC_DIR}/*.cpp")

set (GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest")
add_subdirectory (${GTEST_DIR} EXCLUDE_FROM_ALL)
include_directories ("${GTEST_DIR}/include")


add_custom_target (build_test COMMAND "")

foreach (TEST_SRC ${TEST_SRC_FILES})
	get_filename_component (TEST_NAME "${TEST_SRC}" NAME_WE)

	add_executable ("${TEST_NAME}" EXCLUDE_FROM_ALL ${TEST_SRC})
	add_dependencies ("${TEST_NAME}" "${QMONIX_LIB}")
	target_link_libraries (${TEST_NAME} "gtest" "gtest_main"
		"${QMONIX_LIB}" "gcov")

	set (TEST_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/Testing/bin")
	set_target_properties("${TEST_NAME}" PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_DIR}")

	add_test ("${TEST_NAME}" "${TEST_OUTPUT_DIR}/${TEST_NAME}")

	add_dependencies (build_test "${TEST_NAME}")
endforeach()

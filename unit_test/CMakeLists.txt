cmake_minimum_required(VERSION 3.0.0)
find_package(GTest REQUIRED)
include_directories(../src ${GTEST_INCLUDE_DIRS})

file(GLOB unit_test_src "*.cpp")

add_executable(unit_test ${unit_test_src})

target_link_libraries(unit_test ${GTEST_BOTH_LIBRARIES} pthread)

gtest_discover_tests(unit_test)

set(CMAKE_BUILD_TYPE "Debug")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(CodeCoverage)

append_coverage_compiler_flags()

setup_target_for_coverage_lcov(
    NAME unit_test_coverage_html                # New target name
    EXECUTABLE unit_test                        # Executable in PROJECT_BINARY_DIR
    DEPENDENCIES unit_test                      # Dependencies to build first
    BASE_DIRECTORY "../"                        # Base directory for report
                                                #  (defaults to PROJECT_SOURCE_DIR)
    EXCLUDE "${PROJECT_SOURCE_DIR}/unit_test/*" "/usr/*"
    NO_DEMANGLE                                 # Don't demngle C++ symbols
                                                #  even if c++filt is found
    )

setup_target_for_coverage_gcovr(
    NAME unit_test_coverage                     # New target name
    EXECUTABLE unit_test                        # Executable in PROJECT_BINARY_DIR
    DEPENDENCIES unit_test                      # Dependencies to build first
    BASE_DIRECTORY "../"                        # Base directory for report
                                                #  (defaults to PROJECT_SOURCE_DIR)
    EXCLUDE "${PROJECT_SOURCE_DIR}/unit_test/*" "/usr/*"
    NO_DEMANGLE                                 # Don't demngle C++ symbols
                                                #  even if c++filt is found
    )


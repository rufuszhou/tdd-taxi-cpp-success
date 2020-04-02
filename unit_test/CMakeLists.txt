cmake_minimum_required(VERSION 3.0.0)
find_package(GTest REQUIRED)
include_directories(.. ${GTEST_INCLUDE_DIRS})

file(GLOB unit_test_src "*.cpp")

add_executable(unit_test ${unit_test_src})

target_link_libraries(unit_test ${GTEST_BOTH_LIBRARIES} pthread)

gtest_discover_tests(unit_test)

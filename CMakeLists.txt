cmake_minimum_required(VERSION 3.0.0)
project(tdd_taxi_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(tdd_taxi_cpp main.cpp ride.cpp bill.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(unit_test)

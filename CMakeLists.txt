cmake_minimum_required(VERSION 3.10)
project(sharedlib)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
include_directories(sharedLib/include)

add_executable(sharedlib main.cpp sharedLib/library.h sharedLib/validation.cpp sharedLib/aclPermission.cpp sharedLib/Tests/validationTests.cpp sharedLib/Tests/aclPermissionTests.cpp sharedLib/Tests/libraryTests.cpp sharedLib/calculationOforder.cpp sharedLib/Tests/calculationTests.cpp)
target_link_libraries(sharedlib  gtest gtest_main)
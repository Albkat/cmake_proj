cmake_minimum_required(VERSION 3.12)


# define project
project(cmake_project VERSION 0.1 LANGUAGES CXX)
message("Version: ${CMAKE_VERSION}")

# some variables
set(MY_NAME "Albert")
message("My name is ${MY_NAME}")

if (CMAKE_VERSION VERSION_LESS "3.27")
   message(FATAL_ERROR "Minimum required CMake version")
endif()

set(SOFTWARE "mctc-lib;toml-f;tblite")
message("${SOFTWARE}")
list(LENGTH SOFTWARE L) # 3

include(src/CMakeLists.txt)

add_executable(pr src/main.cpp)
add_executable(test1 test/test_print.cpp)

message("SOURCE: ${PROJECT_SOURCE_DIR}")
message("VERSION: ${PROJECT_VERSION}")

# tests
enable_testing()
message("Are the CTest enabled? ${BUILD_TESTING}")

add_test(NAME basic_set COMMAND test1)

cmake_minimum_required(VERSION 3.12)

# define project
project(cmake_project VERSION 0.1 LANGUAGES CXX)
message(VERBOSE "Version: ${CMAKE_VERSION}")

# some variables
set(MY_NAME "Albert")
message(TRACE "My name is ${MY_NAME}")

if (CMAKE_VERSION VERSION_LESS "3.27")
   message(FATAL_ERROR "Minimum required CMake version")
endif()

set(SOFTWARE "mctc-lib;toml-f;tblite")
message(DEBUG "${SOFTWARE}")
list(LENGTH SOFTWARE L) # 3

include(src/CMakeLists.txt)

add_executable(pr src/main.cpp)
add_executable(test1 test/test_print.cpp)

message(STATUS "SOURCE: ${PROJECT_SOURCE_DIR}")
message(STATUS "VERSION: ${PROJECT_VERSION}")

# tests
enable_testing()
message(STATUS "Are the CTest enabled? ${BUILD_TESTING}")

add_test(NAME basic_set COMMAND test1)

# add installation directory conventions
include(GNUInstallDirs)

message("\nCheck installation conventions for GNUInstallDirs:")
message("base directory " ${CMAKE_INSTALL_PREFIX})
message("include public header files  " ${CMAKE_INSTALL_INCLUDEDIR})
message("install exe " ${CMAKE_INSTALL_BINDIR})
message("lib directory " ${CMAKE_INSTALL_LIBDIR} "\n")

# options
option(ME "Who is this?" ON)

if (ME)
   message("Hey, it's me!\n")
else()
   message(FATAL_ERROR "Sorry, I don't know you")
endif()

message(DEBUG "This only will be printed for debug log level or higher.")

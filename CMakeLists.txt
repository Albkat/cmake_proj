cmake_minimum_required(VERSION 3.20)

# print info about CMake
message(DEBUG "CMake version: ${CMAKE_VERSION}")

# define project
project("Guess Game" VERSION 0.1 LANGUAGES CXX)

# print information about the project
message("Project: ${PROJECT_NAME}")
message("Source: ${PROJECT_SOURCE_DIR}")
message("Version: ${PROJECT_VERSION}")

# some variables
set(WITH_OpenMPI "allow for parallelization" OFF)
set(WITH_fmt "nice and safe format" ON)

if (CMAKE_VERSION VERSION_LESS "3.20")
   message(FATAL_ERROR "Minimum required CMake version")
endif()

set(PARAMS "time" "efficiency")
list(LENGTH PARAMS L) # 3
message(TRACE "Number of parameters: ${L}")

include(src/CMakeLists.txt)

add_executable(pr src/main.cpp)
add_executable(test1 test/test_print.cpp)


# tests
enable_testing()
message("Are the CTest enabled? ${BUILD_TESTING}")

add_test(NAME basic_set COMMAND test1)

include(GNUInstallDirs)

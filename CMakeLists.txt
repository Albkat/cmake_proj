cmake_minimum_required(VERSION 3.20)

# print info about CMake
message(DEBUG "CMake version: ${CMAKE_VERSION}")

# define project
project("Number guessing game" VERSION 0.2 LANGUAGES CXX)

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

# building process
include(src/CMakeLists.txt)
#add_library(game src/game/game.cpp src/game/check.cpp)

add_executable(guessGame src/main.cpp)

target_link_libraries(guessGame game)


# tests
enable_testing()
add_subdirectory(tests)

include(GNUInstallDirs)
#Central unit for the build 
cmake_minimum_required(VERSION 3.24)

# print info about CMake
message(DEBUG "CMake version: ${CMAKE_VERSION}")
message("Generator: ${CMAKE_GENERATOR}")
message("Source: ${CMAKE_SOURCE_DIR}")

# define project
project(
   "guessGame" 
   VERSION 0.2 
   LANGUAGES CXX
)

enable_testing()

# print information about the project
message("Project: ${PROJECT_NAME}")

# GNU installation conventions  
include(GNUInstallDirs)

# building process
add_subdirectory(cmake_config)
message(FATAL_ERROR "STOP: ${CMAKE_INSTALL_PREFIX}")

set(PARAMS "time" "efficiency")
list(LENGTH PARAMS L) # 3
message(TRACE "Number of parameters: ${L}")

add_subdirectory(src/game)
#add_library(game src/game/game.cpp src/game/check.cpp)

add_executable(guessGame src/main.cpp)

target_link_libraries(guessGame game)


# tests
enable_testing()
add_subdirectory(tests)

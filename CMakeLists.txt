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

# source
set(srcs)
set(prog)
add_subdirectory(src)
message(FATAL_ERROR "here: ${prog} ${srcs}")

add_executable(guessGame src/main.cpp)

target_link_libraries(guessGame game)


# tests
enable_testing()
add_subdirectory(tests)

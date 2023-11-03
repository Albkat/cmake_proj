#Central unit for the build 
cmake_minimum_required(VERSION 3.24)

# print info about CMake
message(DEBUG "CMake version: ${CMAKE_VERSION}")
message("Generator: ${CMAKE_GENERATOR}")
message("Source: ${CMAKE_SOURCE_DIR}")

# if use openmp
option(WITH_OpenMP "if the parallelization should be used" TRUE)
option(WITH_LAPACK "if LAPACK is used" TRUE)


# define project
project(
   "guessGame" 
   VERSION 0.2 
   LANGUAGES CXX
)

enable_testing()

# print information about the project
message(DEBUG "Project: ${PROJECT_NAME}")

# GNU installation conventions  
include(GNUInstallDirs)

# building process
add_subdirectory(cmake_config)

# source
set(srcs)
set(prog)
add_subdirectory(src)

# search for LAPACK fiind module
find_package("LAPACK" REQUIRED)
find_package("OpenMP" REQUIRED)

# create include dir
if(NOT EXISTS "${CMAKE_BINARY_DIR}/include")
   file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include")
endif()

# add object library and specify properties
add_library("${PROJECT_NAME}-object" OBJECT ${srcs})
set_target_properties(
   "${PROJECT_NAME}-object" 
   PROPERTIES
   Fortran_MODULE_DIRECTORY "${CMAKE_BINARY_DIR}/include"
)

target_link_libraries(
   "${PROJECT_NAME}-object"
   PUBLIC
   "LAPACK::LAPACK"
   "$<$<BOOL:${WITH_OpenMP}>:OpenMP::OpenMP_CXX>"
)

message(FATAL_ERROR "here: $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>")

add_executable(guessGame src/main.cpp)
target_link_libraries(guessGame game)


# tests
enable_testing()
add_subdirectory(tests)

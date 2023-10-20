# Build type
if (NOT CMAKE_BUILD_TYPE)
   set(
      CMAKE_BUILD_TYPE "RelWithDebInfo"
      CACHE STRING "Build type"
      FORCE
   )
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# user-configurable variables
option(WITH_OpenMPI "allow for parallelization" OFF)
option(WITH_fmt "nice and safe format" ON) 

# compiler-related information
message(VERBOSE "Compiler information: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} PARENT_SCOPE)
message("Module path: ${CMAKE_MODULE_PATH}")


# search for specific git library
message(VERBOSE "Search for find scripts in: ${CMAKE_MODULE_PATH}")
find_package("git1" REQUIRED)

# create git metadata file
set(version ${PROJECT_VERSION})
execute_process(COMMAND git rev-parse HEAD
   RESULT_VARIABLE git_res
   OUTPUT_VARIABLE hash)
string(REGEX REPLACE "\n$" "" hash ${hash})
string(TIMESTAMP present "%d-%m-%Y")
set(user $ENV{USERNAME})
set(origin ${CMAKE_HOST_SYSTEM_NAME})
configure_file(
   "${PROJECT_SOURCE_DIR}/cmake_config/assets/version.cpp" 
   "${PROJECT_BINARY_DIR}/guess_version.h"
   @ONLY
)
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
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} PARENT_SCOPE)

# search for packges
message(VERBOSE "Search for find scripts in: ${CMAKE_MODULE_PATH}")
find_package("git" REQUIRED)

message(VERBOSE "The module 1: ${_lib}")
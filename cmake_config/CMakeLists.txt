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
   

# defined vars
if (NOT DEFINED "${PROJECT_NAME}-dep")
   set("${PROJECT_NAME}-dep" "lib1" "lib2")
endif()
message(DEBUG "name of PROJECT_NAME-dep: ${${PROJECT_NAME}-dep}")


# compiler-related information
message(VERBOSE "compiler information: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

message(FATAL_ERROR "STOP")

add_subdirectory(../src/game)

# add game
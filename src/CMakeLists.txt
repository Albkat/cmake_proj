message(STATUS "project: ${PROJECT_NAME}")

# defined vars
if (NOT DEFINED "${PROJECT_NAME}-dep")
   set("${PROJECT_NAME}-dep" "lib1" "lib2")
endif()
message(TRACE "name of PROJECT_NAME-dep: ${${PROJECT_NAME}-dep}")

# compiler-related information
message(VERBOSE "compiler information: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if (NOT CMAKE_BUILD_TYPE)
   set(
      CMAKE_BUILD_TYPE "RelWithDebInfo"
   )
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

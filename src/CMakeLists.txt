message(TRACE "HERE")
message(STATUS "project: ${PROJECT_NAME}")

# defined vars
if (NOT DEFINED "${PROJECT_NAME}-dep")
   set("${PROJECT_NAME}-dep" "lib1" "lib2")
endif()
message(TRACE "name: ${${PROJECT_NAME}-dep}")

# compiler related
message(VERBOSE "compiler: ${CMAKE_Fortran_COMPILER_VERSION}")
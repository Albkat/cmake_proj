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
find_package("BLAS" REQUIRED)

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
   POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(
   "${PROJECT_NAME}-object"
   PUBLIC
   "LAPACK::LAPACK"
   "$<$<BOOL:${WITH_OpenMP}>:OpenMP::OpenMP_CXX>"
)

target_include_directories(
   "${PROJECT_NAME}-object"
   PUBLIC 
   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)


# static lib
add_library(
   "lib-${PROJECT_NAME}-static"
   STATIC 
   $<TARGET_OBJECTS:${PROJECT_NAME}-object>
)

target_link_libraries(
   "lib-${PROJECT_NAME}-static"
   PUBLIC
   ${LAPACK_LIBRARIES}
)

target_include_directories(
   "lib-${PROJECT_NAME}-static"
   PUBLIC 
   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> # evaluated at build tree
)

set_target_properties(
   "lib-${PROJECT_NAME}-static"
   PROPERTIES 
   OUTPUT_NAME "${PROJECT_NAME}"
   POSITION_INDEPENDENT_CODE ON
)

# shared lib
#add_library(
#   "lib-${PROJECT_NAME}-shared"
#   SHARED 
#   $<TARGET_OBJECTS:${PROJECT_NAME}-object>
#)

#target_link_libraries(
#   "lib-${PROJECT_NAME}-shared"
#   PUBLIC 
#   ${BLAS_DIRECTORIES}
#)

#set_target_properties(
#   "lib-${PROJECT_NAME}-shared"
#   PROPERTIES 
#   OUTPUT_NAME "${PROJECT_NAME}"
#   POSITION_INDEPENDENT_CODE ON
#   LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}"
#)

#target_include_directories(
#   "lib-${PROJECT_NAME}-shared"
#   PUBLIC
#   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
#)

# executable
add_executable(
   "${PROJECT_NAME}-exe" 
   ${prog}   
)

target_link_libraries(
   "${PROJECT_NAME}-exe"
   PRIVATE
   "lib-${PROJECT_NAME}-static"
)

target_include_directories(
   "${PROJECT_NAME}-exe"
   PRIVATE 
   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

# installation rules
if (WITH_OpenMP)
   install(
      TARGETS
      "${PROJECT_NAME}-exe"
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
   )
else()
   install(
      TARGETS
      "${PROJECT_NAME}-exe"
      "lib-${PROJECT_NAME}-shared" 
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
      LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
   )
endif()
# tests
enable_testing()
add_subdirectory(tests)
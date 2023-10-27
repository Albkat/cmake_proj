macro(
   "guess_"
   package
   methods
   url
)

string(TOLOWER ${package} _pkg_small)
string(TOUPPER ${package} _pkg_big)

foreach(method ${methods})
   # search with cmake
   if("${method}" STREQUAL "cmake")
      find_package("${package}" CONFIG QUIET )
      if("${package}_FOUND")   
         message("package found via cmake")
      endif()
   endif()

   if("${method}" STREQUAL "pkgconf")
      find_package("PkgConfig" QUIET)
      pkg_check_modules("${_pkg_small}" QUIET "${package}")
   endif()

   if("${method}" STREQUAL "subproject")
      if(NOT DEFINED  "${_pkg_uc}_SUBPROJECT")
         set("${_pkg_uc}_SUBPROJECT" "subprojects/${package}")
      endif()

      set("${_pkg_uc}_SOURCE_DIR" "${PROJECT_SOURCE_DIR}/${${_pkg_uc}_SUBPROJECT}")
      set("${_pkg_uc}_BINARY_DIR" "${PROJECT_BINARY_DIR}/${${_pkg_uc}_SUBPROJECT}")

      if(EXISTS "${${_pkg_uc}_SOURCE/DIR}/CMakeLists.txt")
         message(STATUS "Include ${package} from ${${_pkg_uc}_SUBPROJECT}")
         add_subdirectory(
            "${${_pkg_uc}_SOURCE_DIR}"
            "${${_pkg_uc}_BINARY_DIR}"
         )
         add_library("${package}::${package}" INTERFACE IMPORTED)
         target_link_libraries("${package}::${package}" INTERFACE "${package}")

         if (NOT EXISTS "${${_pkg_uc}_BINARY_DIR}/include")
            file(MAKE_DIRECTORY "${${_pkg_uc}_BINARY_DIR}/include")
         endif()

         break()
      endif()
   endif()

   if("${method}" STREQUAL "fetch")
      message(STATUS "Retrieve ${package} from ${url}")
      include(FetchContent)
      FetchContent_Declare(
         "${_pkg_small}"
         GIT_REPOSITORY "${_url}"
         GIT_TAG "HEAD"
      )

      FetchContent_GetProperties("${_pkg_small}")
      if(NOT "${${_pkg_small}_POPULATED}")
         FetchContent_Populate("${_pkg_small}")
      endif()
      add_library("${package}::${package}" INTERFACE IMPORTED)
      target_link_libraries("${package}::${package}" INTERFACE "${package}")

      break()
      
   endif()
endforeach()

unset(_pkg_small)
unset(_pkg_big)

# sanity check
if(NOT TARGET "${package}::${package}")
   message(FATAL_ERROR "could not find dependency ${package}")
endif()
endmacro()
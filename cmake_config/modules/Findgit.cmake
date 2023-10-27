# define custom module to find the lol package

# set package-specific variables
set(_lib "git")
set(_pkg "git_learn")
set(_url "https://github.com/Albkat/git_learn")

if(NOT DEFINED "${_pkg}_FIND_METHOD")
   set("${_pkg}_FIND_METHOD" "cmake" "pkgconf" "subproject" "fetch")
endif()

# check if the package is found
include("${CMAKE_CURRENT_LIST_DIR}/packages.cmake")
guess_("${_lib}" "${${_pkg}_FIND_METHOD}" "${_url}")

# unset variables
unset(_lib)
unset(_pkg)
unset(_url)
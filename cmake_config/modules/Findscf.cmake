set(_lib "scf")
set(_pkg "scf_mod")
set(_url "https://github.com/Albkat/scf")

set(_methods "cmake" "pkgconf" "subproject" "fetch")
include("${CMAKE_CURRENT_LIST_DIR}/packages.cmake")
guess_("${_lib}" "${_methods}" "${_url}")

unset(_lib)
unset(_pkg)
unset(_url)
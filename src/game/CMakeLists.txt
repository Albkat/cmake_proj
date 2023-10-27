# create library
#add_library(game game.cpp check.cpp input.cpp)
set(_dir ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND srcs 
   "${_dir}/game.cpp"
   "${_dir}/check.cpp"
   "${_dir}/input.cpp"
)

set(srcs ${srcs} PARENT_SCOPE)
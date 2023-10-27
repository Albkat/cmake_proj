add_subdirectory("game")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND prog
   "${dir}/main.cpp"
)

set(srcs ${srcs} PARENT_SCOPE)
set(prog ${prog} PARENT_SCOPE)
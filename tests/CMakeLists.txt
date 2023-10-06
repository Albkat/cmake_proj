project(regression_tests)

# create an executable
add_executable(test1 test_not_related.cpp)
add_executable(test2 test_range.cpp)
add_executable(test3 test_seed.cpp ../src/game/game.cpp)

# add tests
add_test(NAME not_related COMMAND test1)
add_test(NAME range_test COMMAND test2)
add_test(NAME seed COMMAND test3)
   

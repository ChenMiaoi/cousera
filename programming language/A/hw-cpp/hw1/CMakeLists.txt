enable_testing()

add_executable(test_main main.cc hw1.cc)
target_link_libraries(test_main gtest)
add_test(NAME test_hw1 COMMAND test_main)

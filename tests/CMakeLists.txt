project (app_tests)
enable_testing()


# UDF = User Defined Types
add_executable(app_tests SampleAppTests.cpp )
add_executable(entity_tests EntityTests.cpp)

target_link_libraries(app_tests
        gtest_main
        )
target_link_libraries(entity_tests
        gtest_main
        )

add_test(test_all app_tests entity_tests)
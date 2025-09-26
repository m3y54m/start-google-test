# Enable testing
enable_testing()

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create an executable for the unit tests
add_executable(test_calc test_calc.cpp)

# Link the test executable with Google Test and the Calculator library
target_link_libraries(test_calc ${GTEST_LIBRARIES} pthread calc)

# Add a CTest test target
add_test(NAME CalculatorTests COMMAND test_calc)

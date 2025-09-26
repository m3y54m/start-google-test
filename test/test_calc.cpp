#include <gtest/gtest.h>     // Include Google Test framework
#include "calc.h"      // Include Calculator header

// Test fixture for Calculator
class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc; // Calculator instance to use in tests
};

// Test addition function
TEST_F(CalculatorTest, TestAddition) {
    EXPECT_EQ(calc.add(2, 3), 5); // Check if 2 + 3 equals 5
    EXPECT_EQ(calc.add(-1, -1), -2); // Check if -1 + -1 equals -2
}

// Test subtraction function
TEST_F(CalculatorTest, TestSubtraction) {
    EXPECT_EQ(calc.subtract(5, 3), 2); // Check if 5 - 3 equals 2
    EXPECT_EQ(calc.subtract(0, 1), -1); // Check if 0 - 1 equals -1
}

// Main entry point for tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

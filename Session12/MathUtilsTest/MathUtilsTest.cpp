#include "gtest/gtest.h"
#include "../MathUtils/MathUtils.h"

TEST(MathUtilsTest, Addition) {
    EXPECT_EQ(MathUtils::Add(2, 3), 5);
}

TEST(MathUtilsTest, Subtraction) {
    EXPECT_EQ(MathUtils::Subtract(10, 4), 6);
}

TEST(MathUtilsTest, Multiplication) {
    EXPECT_EQ(MathUtils::Multiply(3, 7), 21);
}

TEST(MathUtilsTest, Division) {
    EXPECT_EQ(MathUtils::Divide(10, 2), 5);
}

TEST(MathUtilsTest, DivisionByZeroThrows) {
    EXPECT_THROW(MathUtils::Divide(10, 0), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
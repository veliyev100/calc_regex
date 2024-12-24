
#include <gtest/gtest.h>
#include "calculator.h"

// Тестирование функции applyOperation
TEST(CalculatorTest, ApplyOperationAddition) {
    EXPECT_DOUBLE_EQ(applyOperation(5, 3, '+'), 8.0);
}

TEST(CalculatorTest, ApplyOperationSubtraction) {
    EXPECT_DOUBLE_EQ(applyOperation(5, 3, '-'), 2.0);
}

TEST(CalculatorTest, ApplyOperationMultiplication) {
    EXPECT_DOUBLE_EQ(applyOperation(5, 3, '*'), 15.0);
}

TEST(CalculatorTest, ApplyOperationDivision) {
    EXPECT_DOUBLE_EQ(applyOperation(6, 3, '/'), 2.0);
}

TEST(CalculatorTest, ApplyOperationDivisionByZero) {
    EXPECT_THROW(applyOperation(6, 0, '/'), const char*);
}

// Тестирование функции isValidExpression
TEST(CalculatorTest, IsValidExpressionValid) {
    EXPECT_TRUE(isValidExpression("5 + 3 * 2 - 4 / 2"));
    EXPECT_TRUE(isValidExpression("123 + 456.78 - 90.0 * 2.1 / 3"));
    EXPECT_TRUE(isValidExpression("5"));
}

TEST(CalculatorTest, IsValidExpressionInvalid) {
    EXPECT_FALSE(isValidExpression("5 + 3 @ 2"));
    EXPECT_FALSE(isValidExpression("5 ** 3"));
    EXPECT_FALSE(isValidExpression("5 / 0"));
    EXPECT_FALSE(isValidExpression("5 + + 3"));
}

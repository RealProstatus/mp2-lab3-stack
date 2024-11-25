#include"../src/Calc.h"
#include"../src/Calc.cpp"

#include"gtest.h"

//тесты на верных выражениях
TEST(Calc, correctness_of_calculating_cos) {
	Calc c;
	EXPECT_EQ(2 + cos(3.1415926), c.calc("2 + cos(3.1415926)"));
}
TEST(Calc, correctness_of_calculating_sin) {
	Calc c;
	EXPECT_EQ(2 + sin(3.1415926), c.calc("2 + sin(3.1415926)"));
}
TEST(Calc, correctness_of_calculating_exp) {
	Calc c;
	EXPECT_EQ((10 * 2 + exp(0))*pow(10,32), c.calc("(10*2 + exp(0))*(10^32)"));
}

TEST(Calc, correctness_of_calculating_negative_subexpression) {
	Calc c;
	c.setInfix("2+(-3+2)");
	EXPECT_EQ(2 + (-3+2), c.calc());
}

TEST(Calc, correctness_expression_1) {
	Calc c;
	double res = c.calc("10+(32.64/6)^3-(3.2^0*48)");
	EXPECT_EQ(10 + pow(32.64 / 6, 3) - (pow(3.2, 0) * 48), res);
}

TEST(Calc, correctness_expression_2) {
	Calc c;
	double res = c.calc("exp(2.6)+32.8^(-3+489.7*3.2)");
	EXPECT_EQ(exp(2.6) + pow(32.8, -3 + 489.7 * 3.2), res);
}

TEST(Calc, correctness_expression_3) {
	Calc c;
	double res = c.calc("3^(cos(10)^2 + sin(10)^2)");
	EXPECT_EQ(pow(3,cos(10)*cos(10) + sin(10)*sin(10)), res);
}

TEST(Calc, correctness_expression_4) {
	Calc c;
	double res = c.calc("148.23^(-125.48-90.54*exp(23)-4)");
	EXPECT_EQ(pow(148.23, -125.48 - 90.54 * exp(23) - 4), res);
}

TEST(Calc, correctness_expression_5) {
	Calc c;
	double res = c.calc("exp(cos(10)^2 + sin(10))^20.5");
	EXPECT_EQ(pow(exp(cos(10)*cos(10) + sin(10)), 20.5), res);
}

//тесты на ввод неверных выражений
TEST(Calc, throws_when_char_stack_overflow) {
	Calc c;
	ASSERT_ANY_THROW(c.calc("15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15+(15))))))))))))))))))"));
}

TEST(Calc, throws_when_wrong_bracket_sequence) {
	Calc c;
	ASSERT_ANY_THROW(c.calc("(10+12))"));
}
TEST(Calc, throws_when_unsupported_operation) {
	Calc c;
	ASSERT_ANY_THROW(c.calc("(10%12)"));
}
TEST(Calc, throws_when_too_much_opearations) {
	Calc c;
	ASSERT_ANY_THROW(c.calc("(10//12)"));
}
TEST(Calc, throws_when_not_enough_operands) {
	Calc c;
	ASSERT_ANY_THROW(c.calc("(10/)"));
}
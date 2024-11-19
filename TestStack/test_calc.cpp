#include"../src/Calc.h"
#include"../src/Calc.cpp"

#include"gtest.h"

TEST(Calc, correctness_of_calculating_cos) {
	Calc c;
	EXPECT_EQ(2 + cos(3), c.calc("2 + cos(3)"));
}
TEST(Calc, correctness_of_calculating_sin) {
	Calc c;
	EXPECT_EQ(2 + sin(3), c.calc("2 + sin(3)"));
}
TEST(Calc, correctness_of_calculating_exp) {
	Calc c;
	EXPECT_EQ(2 + exp(3), c.calc("2 + exp(3)"));
}

TEST(Calc, correctness_of_calculating_negative_subexpression) {
	Calc c;
	c.setInfix("2+(-3+2)");
	EXPECT_EQ(2 + (-3+2), c.calc());
}

TEST(Calc, correctness_of_calculating_simple_numbers) {
	Calc c;
	c.setInfix("2+2*2");
	c.convertToPostfix();
	EXPECT_EQ("2 2 2 * + ",c.getPostfix());
	EXPECT_EQ(2 + 2 * 2, c.calcUsingPostfix());
	EXPECT_EQ(2 + 2 * 2, c.calc());
}

TEST(Calc, correctness_of_calculating_FP_numbers) {
	Calc c;
	c.setInfix("2.2+2*2");
	c.convertToPostfix();
	EXPECT_EQ("2.2 2 2 * + ", c.getPostfix());
	EXPECT_EQ(2.2 + 2 * 2, c.calcUsingPostfix());
	EXPECT_EQ(2.2 + 2 * 2, c.calc());
}

TEST(Calc, correctness_of_calculating_with_brackets) {
	Calc c;
	c.setInfix("2.2*(3.1+4.0)");
	c.convertToPostfix();
	EXPECT_EQ("2.2 3.1 4.0 + * ", c.getPostfix());
	EXPECT_EQ(2.2 * (3.1 + 4.0), c.calcUsingPostfix());
	EXPECT_EQ(2.2 * (3.1 + 4.0), c.calc());
}
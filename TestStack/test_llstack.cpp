#include"../sln/LLStack.h"

#include"gtest.h"

TEST(LLStack, can_create_llstack) {
	ASSERT_NO_THROW(LLStack<int> s);
}

TEST(LLStack, new_llstack_is_empty) {
	LLStack<int> s;
	ASSERT_TRUE(s.isEmpty());
}

TEST(LLStack, new_llstack_is_not_full) {
	LLStack<int> s;
	ASSERT_FALSE(s.isFull());
}

TEST(LLStack, can_create_copied_stack) {
	LLStack<int> ts;
	ASSERT_NO_THROW(LLStack<int> s(ts));
}

TEST(LLStack, copied_stack_has_its_own_memory) {
	LLStack<int> ts;
	LLStack<int> s(ts);
	s.push(2531);
	ASSERT_TRUE(ts.isEmpty());
}

TEST(LLStack, copied_stack_is_equal_to_the_source_one) {
	LLStack<int> ts;
	LLStack<int> s(ts);
	EXPECT_TRUE(s == ts);
}

TEST(LLStack, can_assign_stack_to_itself) {
	LLStack<int> s;
	ASSERT_NO_THROW(s = s);
}

TEST(LLStack, can_assign_equal_stack) {
	LLStack<int> s1;
	LLStack<int> s2;
	ASSERT_NO_THROW(s1 = s2);
}

TEST(LLStack, can_push_into_empty_stack) {
	LLStack<int> s;
	ASSERT_NO_THROW(s.push(2531));
}

TEST(LLStack, cant_pop_from_empty_stack) {
	LLStack<int> s;
	ASSERT_ANY_THROW(s.pop());
}

TEST(LLStack, cant_top_from_empty_stack) {
	LLStack<int> s;
	ASSERT_ANY_THROW(s.top());
}

TEST(LLStack, can_pop_from_full_stack) {
	LLStack<int> s;
	for (int i = 0; i < 5; i++)
		s.push(i);
	ASSERT_NO_THROW(s.pop());
}

TEST(LLStack, can_top_from_full_stack) {
	LLStack<int> s;
	for (int i = 0; i < 5; i++)
		s.push(i);
	ASSERT_NO_THROW(s.top());
}

TEST(LLStack, cleared_stack_is_empty) {
	LLStack<int> s;
	for (int i = 0; i < 5; i++)
		s.push(i);
	s.clr();
	ASSERT_TRUE(s.isEmpty());
}
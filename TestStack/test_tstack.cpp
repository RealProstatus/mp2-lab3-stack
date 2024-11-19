#include "../src/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size) {
  ASSERT_NO_THROW(TStack<int> m(5));
}

TEST(TStack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_copied_stack) {
	TStack<int> ts;
	ASSERT_NO_THROW(TStack<int> s(ts));
}

TEST(TStack, copied_stack_has_its_own_memory) {
	TStack<int> ts;
	TStack<int> s(ts);
	s.push(2531);
	ASSERT_TRUE(ts.isEmpty());
}

TEST(TStack, copied_stack_is_equal_to_the_source_one) {
	TStack<int> ts;
	TStack<int> s(ts);
	EXPECT_TRUE(s == ts);
}

TEST(TStack, can_assign_stack_to_itself) {
	TStack<int> s;
	ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_assign_stacks) {
	TStack<int> ts(5);
	TStack<int> s(6);
	ASSERT_NO_THROW(s = ts);
}

TEST(TStack, can_assign_copied_stacks) {
	TStack<int> ts;
	TStack<int> s(ts);
	ASSERT_NO_THROW(s = ts);
}

TEST(TStack, unchanged_stack_is_empty) {
	TStack<int> s;
	EXPECT_TRUE(s.isEmpty());
}

TEST(TStack, can_push_into_empty_stack) {
	TStack<int> s;
	ASSERT_NO_THROW(s.push(2531));
}

TEST(TStack, cant_pop_from_empty_stack) {
	TStack<int> s;
	ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, cant_top_from_empty_stack) {
	TStack<int> s;
	ASSERT_ANY_THROW(s.top());
}

TEST(TStack, full_stack_is_full) {
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.push(i);
	EXPECT_TRUE(s.isFull());
}

TEST(TStack, cant_push_into_full_stack) {
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.push(i);
	ASSERT_ANY_THROW(s.push(2531));
}

TEST(TStack, can_pop_from_full_stack) {
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.push(i);
	ASSERT_NO_THROW(s.pop());
}

TEST(TStack, can_top_from_full_stack) {
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.push(i);
	ASSERT_NO_THROW(s.top());
}

TEST(TStack, cleared_stack_is_empty) {
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.push(i);
	s.clr();
	EXPECT_TRUE(s.isEmpty());
}


#include "pch.h"

#include "stack/MinStack.h"

TEST(MinStack, leetcode)
{
	stack::MinStack first;
	first.push(-2);
	first.push(0);
	first.push(-3);

	EXPECT_EQ(first.getMin(), -3);

	first.pop();

	EXPECT_EQ(first.top(), 0);
	EXPECT_EQ(first.getMin(), -2);
}
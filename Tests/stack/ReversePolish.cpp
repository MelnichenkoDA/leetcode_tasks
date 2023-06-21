#include "pch.h"

#include <stack/ReversePolish.h>

TEST(ReversePolish, leetcode)
{
	EXPECT_EQ(stack::evalRPN({ "2","1","+","3","*" }), 9);
	EXPECT_EQ(stack::evalRPN({ "4","13","5","/","+" }), 6);
	EXPECT_EQ(stack::evalRPN({ "10","6","9","3","+","-11","*","/","*","17","+","5","+" }), 22);
}
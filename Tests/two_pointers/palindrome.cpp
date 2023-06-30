#include "pch.h"

#include "two_pointers/palindrome.h"

TEST(Palindrome, leet)
{
	EXPECT_EQ(two_pointers::isPalindrome("A man, a plan, a canal: Panama"), true);
	EXPECT_EQ(two_pointers::isPalindrome("race a car"), false);
	EXPECT_EQ(two_pointers::isPalindrome(" "), true);
	EXPECT_EQ(two_pointers::isPalindrome("a."), true);
	EXPECT_EQ(two_pointers::isPalindrome("0P"), false);
}
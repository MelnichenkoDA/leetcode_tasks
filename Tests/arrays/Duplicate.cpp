#include "pch.h"

#include <arrays/Duplicate.h>

TEST(Duplicate, leetcode)
{
	std::vector<int> first = { 1 };
	std::vector<int> second = { 1,2,3,1 };
	std::vector<int> third = { 1,2,3,4 };
	std::vector<int> fourth = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

	EXPECT_EQ(Duplicate::containsDuplicate(first), false);
	EXPECT_EQ(Duplicate::containsDuplicate(second), true);
	EXPECT_EQ(Duplicate::containsDuplicate(third), false);
	EXPECT_EQ(Duplicate::containsDuplicate(fourth), true);
}
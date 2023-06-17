#include "pch.h"

#include <arrays/TopKFrequent.h>

namespace
{
	bool check(std::vector<int> const& left, int k, std::vector<int> const& right)
	{
		return TopKFrequent::topKFrequent(left, k) == right;
	}
}

TEST(TopKFrequent, leetcode)
{
	EXPECT_EQ(check({ 1,1,1,2,2,3 }, 2, { 1, 2 }), true);
	EXPECT_EQ(check({ 1 }, 1, { 1 }), true);
}
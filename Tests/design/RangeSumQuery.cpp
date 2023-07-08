#include "pch.h"

#include "design/RangeSumQuery.h"

TEST(RangeSumQuery, leet)
{
	design::NumArray first({ -2, 0, 3, -5, 2, -1 });
	EXPECT_EQ(first.sumRange(0, 2), 1);
	EXPECT_EQ(first.sumRange(2, 5), -1);
	EXPECT_EQ(first.sumRange(0, 5), -3);	
}
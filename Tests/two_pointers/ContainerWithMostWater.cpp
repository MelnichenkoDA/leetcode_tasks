#include "pch.h"

#include "two_pointers/ContainerWithMostWater.h"

TEST(ContainerWithMostWater, leet)
{
	EXPECT_EQ(two_pointers::maxArea({ 1,8,6,2,5,4,8,3,7 }), 49);
	EXPECT_EQ(two_pointers::maxArea({ 1,1 }), 1);
}
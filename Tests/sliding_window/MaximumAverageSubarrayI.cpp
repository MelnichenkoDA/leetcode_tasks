#include "pch.h"

#include "sliding_window/MaximumAverageSubarrayI.h"

TEST(MaximumAverageSubarrayI, leet)
{
	EXPECT_EQ(sliding_window::findMaxAverage({ 1,12,-5,-6,50,3 }, 4), 12.75);
	EXPECT_EQ(sliding_window::findMaxAverage({ 5 }, 1), 5);
	EXPECT_EQ(sliding_window::findMaxAverage({ -1 }, 1), -1);
}
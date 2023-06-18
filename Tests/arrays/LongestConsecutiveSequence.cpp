#include "pch.h"

#include "arrays/LongestConsecutiveSequence.h"
#include "BigCase.h"

TEST(LongestConsecutiveSequence, leetcode)
{
	EXPECT_EQ(arrays::longestConsecutive({ 100,4,200,1,3,2 }), 4);
	EXPECT_EQ(arrays::longestConsecutive({ 0,3,7,2,5,8,4,6,0,1 }), 9);
	EXPECT_EQ(arrays::longestConsecutive({ }), 0);
	EXPECT_EQ(arrays::longestConsecutive({ 1 }), 1);
	EXPECT_EQ(arrays::longestConsecutive({ 1, 5 }), 1);

	EXPECT_EQ(arrays::longestConsecutive(cases::consecutiveSequience), 100000);
}
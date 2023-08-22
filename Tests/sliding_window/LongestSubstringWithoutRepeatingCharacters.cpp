#include "pch.h"

#include "sliding_window/LongestSubstringWithoutRepeatingCharacters.h"

TEST(LongestSubstringWithoutRepeatingCharacters, leet)
{
	EXPECT_EQ(sliding_window::lengthOfLongestSubstring("abcabcbb"), 3);
	EXPECT_EQ(sliding_window::lengthOfLongestSubstring("bbbbb"), 1);
	EXPECT_EQ(sliding_window::lengthOfLongestSubstring("pwwkew"), 3);
	EXPECT_EQ(sliding_window::lengthOfLongestSubstring(" "), 1);
	EXPECT_EQ(sliding_window::lengthOfLongestSubstring("dvdf"), 3);
}
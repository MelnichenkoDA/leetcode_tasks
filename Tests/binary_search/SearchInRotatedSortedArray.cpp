#include "pch.h"

#include "binary_search/SearchInRotatedSortedArray.h"

TEST(SearchInRotatedSortedArray, leet)
{
	EXPECT_EQ(binary_search::search({ 4,5,6,7,0,1,2 }, 0), 4);
	EXPECT_EQ(binary_search::search({ 4,5,6,7,0,1,2 }, 3), -1);
	EXPECT_EQ(binary_search::search({ 1 }, 0), -1);
	EXPECT_EQ(binary_search::search({ 1, 3 }, 3), 1);
	EXPECT_EQ(binary_search::search({ 3,1 }, 1), 1);
}

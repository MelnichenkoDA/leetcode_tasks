#include "pch.h"

#include "binary_search/MinimumInRotatedSortedArray.h"

TEST(MinimumInRotatedSortedArray, leet)
{
	EXPECT_EQ(binary_search::findMin({ 3, 4, 5, 1, 2 }), 1);
	EXPECT_EQ(binary_search::findMin({ 4, 5, 6, 7, 0, 1, 2 }), 0);
	EXPECT_EQ(binary_search::findMin({ 11, 13, 15, 17 }), 11);
	EXPECT_EQ(binary_search::findMin({ 3,1,2 }), 1);
}

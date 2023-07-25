#include "pch.h"

#include <math/RotateImage.h>

namespace 
{
	bool check(std::vector<std::vector<int>> matr, std::vector<std::vector<int>> res)
	{
		math::rotate(matr);
		return std::ranges::all_of(matr, [&res](auto const& test) { return std::ranges::contains(res, test); });
	}
}
TEST(RotateImage, leet)
{
	std::vector<std::vector<int>> matr
	{
		{1, 2, 3},
		{ 4,5,6 },
		{ 7,8,9 }
	};

	std::vector<std::vector<int>> matr2 {{5, 1, 9, 11}, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 }};

	EXPECT_EQ(check(matr2, std::vector<std::vector<int>>{{15, 13, 2, 5}, { 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 }}), true);
}
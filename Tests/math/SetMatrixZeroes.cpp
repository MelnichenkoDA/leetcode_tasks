#include "pch.h"

#include <math/SetMatrixZeroes.h>
#include "../utils/checks.h"

namespace
{
	bool check(std::vector<std::vector<int>> arr, std::vector<std::vector<int>> test)
	{
		math::setZeroes(arr);
		return checks::checkMatrixEqual(arr, test);
	}
}
TEST(SetMatrixZeroes, leet)
{
	EXPECT_EQ(check({ {1,1,1}, {1,0,1},{1,1,1} }, { {1,0,1 }, { 0,0,0 }, { 1,0,1 } }), true);
	EXPECT_EQ(check({ {0,1,2,0}, {3,4,5,2}, {1,3,1,5} }, { {0,0,0,0} ,{0,4,5,0},{0,3,1,0 } }), true);
}
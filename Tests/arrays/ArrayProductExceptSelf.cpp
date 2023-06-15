#include "pch.h"

#include <arrays/ArrayProductExceptSelf.h>

namespace
{
	bool check(const std::vector<int>& mult, const std::vector<int>& res)
	{
		return ArrayProduct::productExceptSelf(mult) == res;
	}

	bool checkWithoutCopy(const std::vector<int>& mult, const std::vector<int>& res)
	{
		auto temp = mult;
		return ArrayProduct::productExceptSelfWithoutCopy(temp) == res;
	}
}

TEST(ArrayProductExceptSelf, letcode)
{
	auto const first = ArrayProduct::productExceptSelf({ 1,2,3,4 });
	std::vector<int> second = { -1,1,0,-3,3 };

	EXPECT_EQ(checkWithoutCopy({ 1,2,3,4 }, { 24, 12, 8, 6 }), true);
	EXPECT_EQ(checkWithoutCopy({ -1,1,0,-3,3 }, { 0, 0, 9, 0, 0 }), true);
}
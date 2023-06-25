#include "pch.h"

#include "stack/GenerateParentheses.h"
#include <algorithm>

namespace
{
	bool check(int n, std::vector<std::string> temp)
	{
		auto res = stack::generateParenthesis(n);
		std::sort(res.begin(), res.end());
		std::sort(temp.begin(), temp.end());
		for (auto const& str : res)
		{
			if (std::find(temp.begin(), temp.end(), str) == temp.end())
				return false;
		}
		
		return true;
	}
}

TEST(GenerateParentheses, leet)
{
	EXPECT_EQ(check(3, { "((()))","(()())","(())()","()(())","()()()" }), true);
	EXPECT_EQ(check(1, { "()" }), true);
}
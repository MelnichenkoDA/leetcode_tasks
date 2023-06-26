#pragma once

#include <vector>
#include <algorithm>

namespace checks
{
	template<typename T>
	bool checkEqual(std::vector<T> const &left, std::vector<T> const &right)
	{
		if (left.size() != right.size()) return false;

		for (auto const& item : left)
		{
			if (std::find(right.cbegin(), right.cend(), item) == right.end())
				return false;
		}

		for (auto const& item : right)
		{
			if (std::find(left.cbegin(), left.cend(), item) == left.end())
				return false;
		}

		return true;
	}
}
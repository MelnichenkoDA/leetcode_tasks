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

	template<typename T>
	bool checkMatrixEqual(std::vector<std::vector<T>> const &matr, std::vector<std::vector<T>> const &res)
	{
		return std::ranges::all_of(matr, [&res](auto const& test) { return std::ranges::contains(res, test); });
	}
}
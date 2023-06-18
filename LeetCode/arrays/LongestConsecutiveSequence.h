#pragma once
#include <vector>
#include <unordered_set>

namespace arrays
{
    int longestConsecutive(std::vector<int> const& nums)
    {
        if (nums.empty()) return 0;

        std::unordered_set<int> entrance(nums.begin(), nums.end());

        int curMax{};
        for (auto i : entrance)
        {
            if (entrance.find(i - 1) == entrance.end())
            {
                int cur = i + 1;
                while (entrance.find(cur) != entrance.end())
                {
                    ++cur;
                }

                curMax = std::max(cur - i, curMax);
            }
        }

        return curMax;
    }
}
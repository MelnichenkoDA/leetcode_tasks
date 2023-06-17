#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace TopKFrequent
{
    std::vector<int> topKFrequent(std::vector<int> const& nums, int k)
    {
        std::unordered_map<int, unsigned> entranceCount;
        for (auto i : nums)
        {
            if (entranceCount.find(i) != entranceCount.end())
                ++entranceCount[i];
            else
                entranceCount[i] = 1;
        }

        std::vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            auto min = std::max_element(entranceCount.begin(), entranceCount.end(), [](auto const p1, auto const p2) { return p1.second < p2.second; });
            res.push_back(min->first);
            entranceCount.erase(min);
        }

        return res;
    }
}
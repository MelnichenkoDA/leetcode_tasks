export module FourSum;

import <vector>;
import <unordered_map>;
import <assert.h>;
import <algorithm>;

export namespace FourSum
{
    std::vector<std::vector<int>> fourSum(std::vector<int> const& nums, int target) 
    {
        std::vector<std::vector<int>> res;
        std::unordered_map<int, std::pair<int, int>> hash;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                hash[nums[i] + nums[j]] = { i, j };
            }
        }

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (auto itr = hash.find(target - (nums[i] + nums[j])); itr != hash.end())
                {
                    auto [a, b] = itr->second;
                    if (a != i && a != j && b != i && b != j)
                    {
                        res.push_back({ nums[a], nums[b], nums[i], nums[j] });
                        break;
                    }
                }
            }
        }
        
        auto last = std::unique(res.begin(), res.end(), 
            [](auto const& left, auto const& right) 
            {
                return std::find(right.begin(), right.end(), left[0]) != right.end()
                    && std::find(right.begin(), right.end(), left[1]) != right.end()
                    && std::find(right.begin(), right.end(), left[2]) != right.end()
                    && std::find(right.begin(), right.end(), left[3]) != right.end();
            });
        res.erase(last, res.end());

        return res;
    }

    void test()
    {
        auto res = fourSum({ 1,0,-1,0,-2,2 }, 0);
        auto res1 = fourSum({ 2,2,2,2,2 }, 8);
    }
}
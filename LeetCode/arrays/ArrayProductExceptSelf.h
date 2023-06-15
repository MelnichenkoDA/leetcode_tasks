#pragma once
#include <vector>

namespace ArrayProduct
{
    std::vector<int> productExceptSelf(std::vector<int> const& nums)
    {
        std::vector<int> res(nums.size(), 0);

        int product = 1; 
        bool hasNull = false;
        for (auto i : nums)
        {
            if (!hasNull && i == 0)
            {
                hasNull = true;
                continue;
            }

            if (hasNull && i == 0) return res;
            
            product *= i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (hasNull && nums[i] == 0) res[i] = product;
            if (!hasNull) res[i] = product / nums[i];
        }

        return res;
    }

    constexpr std::vector<int> productExceptSelfWithoutCopy(std::vector<int> &nums)
    {
        int product = 1;
        bool hasNull = false;
        for (auto i : nums)
        {
            if (!hasNull && i == 0)
            {
                hasNull = true;
                continue;
            }

            if (hasNull && i == 0) return std::vector<int>(nums.size(), 0);

            product *= i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (hasNull && nums[i] != 0) nums[i] = 0;
            else if (hasNull && nums[i] == 0) nums[i] = product;
            else if (!hasNull) nums[i] = product / nums[i];
        }

        return std::move(nums);
    }
}
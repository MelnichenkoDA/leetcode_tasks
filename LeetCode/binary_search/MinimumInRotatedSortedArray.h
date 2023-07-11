#pragma once
#include <vector>

namespace binary_search
{
    int findMin(std::vector<int> const& nums) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int res = nums[left];
        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                res = std::min(nums[left], res);
                break;
            }

            int mid = (left + right) >> 1;
            res = std::min(nums[mid], res);
            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return res;
    }
}

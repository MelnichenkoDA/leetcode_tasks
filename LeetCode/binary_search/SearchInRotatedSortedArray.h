#pragma once
#include <vector>

namespace binary_search
{
    int search(std::vector<int> const& nums, int target)
    {
        const int size = nums.size() - 1;

        int border{};
        if (nums[size] < nums[border])
        {
            int i = size;
            while (nums[i] < nums[border])
                border = i--;
        }

        int left{}, right{ size };
        if (nums[0] > nums[right])
        {
            if (target < nums[0])
                left = border;
            else
                right = border - 1;
        }

        int mid = (left + right) >> 1;
        while (left <= right)
        {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) >> 1;
        }

        return -1;
    }
}
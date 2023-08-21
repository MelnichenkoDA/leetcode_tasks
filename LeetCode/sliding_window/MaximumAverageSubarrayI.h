#pragma once
#include <vector>

namespace sliding_window
{
    double findMaxAverage(std::vector<int> const& nums, int const k) 
    {
        int left{};
        int sum{};
        for (int i = left; i < left + k; ++i)
            sum += nums[i];
        
        int answer = sum;
        while (left + k < nums.size())
        {
            sum += nums[left + k] - nums[left];
            if (answer < sum) answer = sum;
            ++left;
        }

        return double(answer) / k;
    }
}
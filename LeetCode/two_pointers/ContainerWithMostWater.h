#pragma once
#include <vector>

namespace two_pointers
{
    int maxArea(std::vector<int> const& heights) 
    {
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;       
        int curr = std::min(heights[left], heights[right]) * (right - left);

        while (left < right)
        {
            if (heights[left] < heights[right])
                ++left;
            else 
                --right;

            if (auto const temp = std::min(heights[left], heights[right]) * (right - left); temp > curr)
                curr = temp;
        }

        return curr;
    }
}
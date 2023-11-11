#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <emmintrin.h>
using namespace std;

namespace matrices
{
    int matrixSum(std::vector<std::vector<int>> nums) 
    {
        int res{};

		for (auto& row : nums)
			std::sort(row.begin(), row.end());
		
		for (int j = 0; j < nums[0].size(); ++j)
		{
			int currMax = nums[0][j];
			for (int i = 1; i < nums.size(); ++i)
				currMax = std::max(currMax, nums[i][j]);
			
			res += currMax;
		}

        return res;
    }
}
#include <vector>
#include <assert.h>

export module OneDArraySum;

import utils;

export
namespace OneDArraySum
{
	std::vector<int> runningSum(std::vector<int>& nums) 
	{
		for (int i = 1; i < nums.size(); ++i)
		{
			nums[i] += nums[i - 1];
		}

		return nums;
	}

	void test()
	{
		std::vector<int> first = { 1,2,3,4 };
		std::vector<int> second  = { 1,1,1,1,1 };
		std::vector<int> third = { 3,1,2,10,1 };

		assert(utils::compare(runningSum(first), { 1,3,6,10 }));
		assert(utils::compare(runningSum(second), { 1,2,3,4,5 }));
		assert(utils::compare(runningSum(third), { 3,4,6,16,17 }));
	}

}
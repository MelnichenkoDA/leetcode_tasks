#include "pch.h"

int search(const std::vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		if (nums[left] == target)
			return left;
		if (nums[right] == target)
			return right;

		int mid = (left + right) >> 1;
		int current_num = nums[mid];
		if (current_num == target)
			return mid;

		if (current_num > target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

TEST(BinarySearch, test1) {
  EXPECT_EQ(search({ -1,0,3,5,9,12 }, 9), 4);
  EXPECT_EQ(search({ -1,0,3,5,9,12 }, 2), -1);
  EXPECT_EQ(search({ 5 }, 5), 0);
  EXPECT_EQ(search({ 1, 3 }, 2), -1);

  EXPECT_TRUE(true);
}
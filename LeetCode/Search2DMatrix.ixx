#include <vector>
#include <assert.h>

export module Search2DMatrix;

export namespace Search2DMatrix
{
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

			int mid = left + (right - left) / 2;
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

	bool searchMatrix(std::vector<std::vector<int>> const& matrix, int target)
	{
		int left = 0;
		int right = matrix.size() - 1;
		while (left < right)
		{
			auto const mid = left + (right - left) / 2;
			auto const& currentRow = matrix[mid];
			if (target < currentRow.front())
				right = mid - 1;
			else if (target > currentRow.back())
				left = mid + 1;
			else // front < target < back
				left = right = mid;
		}

		return search(matrix[left], target) != -1;
	}	

	void test()
	{
		assert(searchMatrix({ {1, 3, 5, 7} ,{10, 11, 16, 20},{23, 30, 34, 60 } }, 3));
		assert(searchMatrix({ {1, 3, 5, 7} ,{10, 11, 16, 20},{23, 30, 34, 60 } }, 13) == false);
		assert(searchMatrix({ {1, 1 } }, 2) == false);
		assert(searchMatrix({ {1, 3 } }, 3) == true);
		assert(searchMatrix({ {1}, {3} }, 3) == true);
		assert(searchMatrix({ {1}, {3} }, 1) == true);
	}
}
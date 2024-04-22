#include <vector>
#include <cassert>
#include <unordered_map>
#include <map>
#include <chrono>
#include <iostream>
#include <algorithm>

namespace Duplicate
{
	bool containsDuplicate(std::vector<int> const& nums)
	{
		std::unordered_map<int, int> entrance;
		for (auto num : nums)
		{
			if (entrance.find(num) != entrance.cend())
				return true;
			entrance[num];
		}

		return false;
	}

	bool containsDuplicateWithMap(std::vector<int> const& nums)
	{
		std::map<int, int> entrance;
		for (auto num : nums)
		{
			if (entrance.find(num) != entrance.cend())
				return true;
			entrance[num];
		}

		return false;
	}

	bool containsDuplicateSorted(std::vector<int> & nums)
	{
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}

		return false;
	}

	void testHashMap()
	{
		std::vector<int> first = { 1 };
		std::vector<int> second = { 1,2,3,1 };
		std::vector<int> third = { 1,2,3,4 };
		std::vector<int> fourth = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

		auto start = std::chrono::high_resolution_clock::now();
		assert(containsDuplicate(first) == false);
		assert(containsDuplicate(second) == true);
		assert(containsDuplicate(third) == false);
		assert(containsDuplicate(fourth) == true);
		auto end = std::chrono::high_resolution_clock::now();

		auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << "Hash: " << time_taken << "\n";
	}

	void testMap()
	{
		std::vector<int> first = { 1 };
		std::vector<int> second = { 1,2,3,1 };
		std::vector<int> third = { 1,2,3,4 };
		std::vector<int> fourth = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

		auto start = std::chrono::high_resolution_clock::now();
		assert(containsDuplicateWithMap(first) == false);
		assert(containsDuplicateWithMap(second) == true);
		assert(containsDuplicateWithMap(third) == false);
		assert(containsDuplicateWithMap(fourth) == true);
		auto end = std::chrono::high_resolution_clock::now();

		auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << "Map: " << time_taken << "\n";
	}

	void testSort()
	{
		std::vector<int> first = { 1 };
		std::vector<int> second = { 1,2,3,1 };
		std::vector<int> third = { 1,2,3,4 };
		std::vector<int> fourth = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

		auto start = std::chrono::high_resolution_clock::now();
		assert(containsDuplicateSorted(first) == false);
		assert(containsDuplicateSorted(second) == true);
		assert(containsDuplicateSorted(third) == false);
		assert(containsDuplicateSorted(fourth) == true);
		auto end = std::chrono::high_resolution_clock::now();

		auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << "Sort: " << time_taken << "\n";
	}

	void test()
	{
		for (int i = 0; i < 10; ++i)
		{
			testHashMap();
			testMap();
			testSort();
		}		
	}
}
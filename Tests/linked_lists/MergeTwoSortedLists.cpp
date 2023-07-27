#include "pch.h"

#include <linked_list/MergeTwoSortedLists.h>

namespace
{
	bool check(const std::vector<int> first, const std::vector<int> second, const std::vector<int> expected)
	{
		auto l1 = linked_list::fromVector(first);
		auto l2 = linked_list::fromVector(second);

		auto res = linked_list::mergeTwoLists(l1, l2);
		auto exList = linked_list::fromVector(expected);

		return linked_list::equal(res, exList);
	}
}

TEST(MergeTwoSortedLists, leet)
{
	/*using Node = linked_list::ListNode;
	auto first = new Node(1, new Node(2, new Node(4)));
	linked_list::mergeTwoLists();*/

	EXPECT_EQ(check({ 1,2,4 }, { 1,3,4 }, { 1,1,2,3,4,4 }), true);
	EXPECT_EQ(check({ }, { }, { }), true);
	EXPECT_EQ(check({ }, { 0 }, { 0 }), true);
}
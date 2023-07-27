#include <vector>

namespace linked_list
{
	struct ListNode 
	{
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	bool equal(ListNode const* left, ListNode const* right)
	{
		while (left && right)
		{
			if (left->val != right->val) return false;

			left = left->next;
			right = right->next;
		}

		return !left && !right;
	}

	ListNode* fromVector(const std::vector<int> values)
	{
		if (values.empty()) return nullptr;

		ListNode* current = new ListNode(values[0]);
		ListNode* res = current;
		for (int i = 1; i < values.size(); ++i)
		{
			current->next = new ListNode(values[i]);
			if (i < values.size() - 1)
				current = current->next;
		}

		return res;
	}
}

#include "ListNode.h"
#include <cinttypes>

namespace linked_list
{
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* res{};
        ListNode* curr{};

        if (!list1 || !list2) return list1 ? list1 : list2;

        if (list1->val < list2->val)
        {
            curr = list1;
            list1 = list1->next;
        }
        else
        {
            curr = list2;
            list2 = list2->next;
        }

        res = curr;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        while (list1)
        {
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
        }

        while (list2)
        {
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        }

        return res;
    }
}

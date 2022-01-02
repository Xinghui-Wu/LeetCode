/**
 * 23. Merge k Sorted Lists
 * 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * Constraints:
 *   k == lists.length
 *   0 <= k <= 10^4
 *   0 <= lists[i].length <= 500
 *   -10^4 <= lists[i][j] <= 10^4
 *   lists[i] is sorted in ascending order.
 *   The sum of lists[i].length won't exceed 10^4.
 * 
 * Difficulty: Hard
 * Related Topics: Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
 */
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        
        // Bottom Up Merge Sort
        for (int size = 1; size < lists.size(); size <<= 1)
        {
            for (int i = 0; i < lists.size() - size; i += 2 * size)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + size]);
            }
        }
        
        return lists[0];
    }


    /**
     * Merge two sorted lists.
     * This function is derived from the solution to Problem 21.
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        // Create a dummy node (which should be deleted in the end in the actual project).
        ListNode* merged_list = new ListNode();
        // Maintain a current pointer to the merged list.
        ListNode* current = merged_list;

        // Merge the two input sorted linked lists while neither of l1 and l2 is nullptr.
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        // If either l1 or l2 is not nullptr now, connect it to the current pointer.
        if (l1 != nullptr)
        {
            current->next = l1;
        }
        if (l2 != nullptr)
        {
            current->next = l2;
        }

        return merged_list->next;
    }
};


int main()
{
    int l1_val_list[] = {1, 4, 5};
    int l2_val_list[] = {1, 3, 4};
    int l3_val_list[] = {2, 6};
    ListNode* l1 = create_list(l1_val_list, 3);
    ListNode* l2 = create_list(l2_val_list, 3);
    ListNode* l3 = create_list(l3_val_list, 2);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution solution;
    ListNode* merged_list = solution.mergeKLists(lists);

    output_list(merged_list);

    return 0;
}

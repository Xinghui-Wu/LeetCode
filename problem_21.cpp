/**
 * 21. Merge Two Sorted Lists
 * 
 * Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
 * 
 * Constraints:
 *   The number of nodes in both lists is in the range [0, 50].
 *   -100 <= Node.val <= 100
 *   Both l1 and l2 are sorted in non-decreasing order.
 * 
 * Difficulty: Easy
 * Related Topics: Linked List, Recursion
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
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
    int l1_val_list[] = {1, 2, 4};
    int l2_val_list[] = {1, 3, 4};
    ListNode* l1 = create_list(l1_val_list, 3);
    ListNode* l2 = create_list(l2_val_list, 3);

    Solution solution;
    ListNode* merged_list = solution.mergeTwoLists(l1, l2);

    output_list(merged_list);
    cout << endl;
    output_list(l1);
    cout << endl;
    output_list(l2);

    return 0;
}

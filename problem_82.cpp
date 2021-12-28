/**
 * 82. Remove Duplicates from Sorted List II
 * 
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * Return the linked list sorted as well.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [0, 300].
 *   -100 <= Node.val <= 100
 *   The list is guaranteed to be sorted in ascending order.
 * 
 * Difficulty: Medium
 * Related Topics: Linked List, Two Pointers
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* dummy = new ListNode(-1000, head);
        ListNode* predecessor = dummy;
        ListNode* current = head;

        while (current != nullptr)
        {
            // if it's a beginning of duplicates sublist, skip all duplicates.
            if (current->next != nullptr && current->val == current->next->val)
            {
                while (current->next != nullptr && current->val == current->next->val)
                {
                    current = current->next;
                }

                predecessor->next = current->next;
            }
            // Otherwise, move predecessor.
            else
            {
                predecessor = predecessor->next;
            }
            
            current = current->next;
        }

        return dummy->next;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = create_list(val_list, 7);

    Solution solution;
    head = solution.deleteDuplicates(head);

    output_list(head);

    return 0;
}

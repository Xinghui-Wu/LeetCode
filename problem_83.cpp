/**
 * 83. Remove Duplicates from Sorted List
 * 
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
 * Return the linked list sorted as well.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [0, 300].
 *   -100 <= Node.val <= 100
 *   The list is guaranteed to be sorted in ascending order.
 * 
 * Difficulty: Easy
 * Related Topics: Linked List
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* current = head;

        while (current != nullptr)
        {
            if (current->next != nullptr && current->next->val == current->val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        
        return head;
    }
};


int main()
{
    int val_list[] = {1, 1, 2, 3, 3};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    head = solution.deleteDuplicates(head);

    output_list(head);

    return 0;
}

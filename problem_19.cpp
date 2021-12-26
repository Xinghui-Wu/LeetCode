/**
 * 19. Remove Nth Node From End of List
 * 
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Constraints:
 *   The number of nodes in the list is sz.
 *   1 <= sz <= 30
 *   0 <= Node.val <= 100
 *   1 <= n <= sz
 * 
 * Follow up:
 *   Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* current = head;

        // Count the number of nodes in the list.
        int length = 0;
        
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }

        // Remove the only node.
        if (length == 1)
        {
            return nullptr;
        }
        
        // Remove the first node.
        if (n == length)
        {
            return head->next;
        }

        current = head;

        for (size_t i = 1; i < length - n; i++)
        {
            current = current->next;
        }

        current->next = current->next->next;
        
        return head;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    head = solution.removeNthFromEnd(head, 4);

    output_list(head);

    return 0;
}

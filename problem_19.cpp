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
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Let the fast pointer go first and keep the distance from the slow pointer.
        for (size_t i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    head = solution.removeNthFromEnd(head, 2);

    output_list(head);

    return 0;
}

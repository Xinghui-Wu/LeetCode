/**
 * 203. Remove Linked List Elements
 * 
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [0, 10^4].
 *   1 <= Node.val <= 50
 *   0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        while (current->next != nullptr)
        {
            if (current->next->val == val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        
        return dummy->next;
    }
};


int main()
{
    int val_list[] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    ListNode* head = create_list(val_list, 7);

    Solution solution;
    head = solution.removeElements(head, val);

    output_list(head);

    return 0;
}

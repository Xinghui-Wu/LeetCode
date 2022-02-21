/**
 * 24. Swap Nodes in Pairs
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [0, 100].
 *   0 <= Node.val <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Linked List, Recursion
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;
        ListNode* temp1;
        ListNode* temp2;

        while (current->next != nullptr && current->next->next != nullptr)
        {
            temp1 = current->next;
            temp2 = current->next->next->next;

            current->next = temp1->next;
            current->next->next = temp1;
            temp1->next = temp2;

            current = current->next->next;
        }

        return dummy->next;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4};
    ListNode* head = create_list(val_list, 4);

    Solution solution;
    head = solution.swapPairs(head);

    output_list(head);

    return 0;
}

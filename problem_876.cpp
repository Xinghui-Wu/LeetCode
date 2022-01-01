/**
 * 876. Middle of the Linked List
 * 
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [1, 100].
 *   1 <= Node.val <= 100
 * 
 * Difficulty: Easy
 * Related Topics: Linked List, Two Pointers
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5, 6};
    ListNode* head = create_list(val_list, 6);

    Solution solution;
    ListNode* middle_node = solution.middleNode(head);

    output_list(middle_node);

    return 0;
}

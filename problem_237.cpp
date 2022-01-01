/**
 * 237. Delete Node in a Linked List
 * 
 * Write a function to delete a node in a singly-linked list.
 * You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
 * It is guaranteed that the node to be deleted is not a tail node in the list.
 * 
 * Constraints:
 *   The number of the nodes in the given list is in the range [2, 1000].
 *   -1000 <= Node.val <= 1000
 *   The value of each node in the list is unique.
 *   The node to be deleted is in the list and is not a tail node.
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
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main()
{
    int val_list[] = {4, 5, 1, 9};
    ListNode* head = create_list(val_list, 4);
    ListNode* node = head->next;

    Solution solution;
    solution.deleteNode(node);

    output_list(head);

    return 0;
}

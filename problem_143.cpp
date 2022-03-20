/**
 * 143. Reorder List
 * 
 * You are given the head of a singly linked-list.
 * The list can be represented as: L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes.
 * Only nodes themselves may be changed.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [1, 5 * 10^4].
 *   1 <= Node.val <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Linked List, Two Pointers, Stack, Recursion
 */
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;


class Solution
{
public:
    void reorderList(ListNode* head)
    {
        // Save the nodes in a vector.
        vector<ListNode*> node_list;
        ListNode* current = head;

        while (current != nullptr)
        {
            node_list.push_back(current);
            current = current->next;
        }
        
        // Use two pointers to reorder the linked list.
        int i = 0;
        int j = node_list.size() - 1;

        while (i < j)
        {
            node_list[i]->next = node_list[j];
            node_list[j]->next = node_list[i + 1];

            i++;
            j--;
        }

        // Handle the last node.
        node_list[i]->next = nullptr;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    solution.reorderList(head);

    output_list(head);

    return 0;
}

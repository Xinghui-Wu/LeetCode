/**
 * 142. Linked List Cycle II
 * 
 * Given the head of a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
 * It is -1 if there is no cycle.
 * Note that pos is not passed as a parameter.
 * Do not modify the linked list.
 * 
 * Constraints:
 *   The number of the nodes in the list is in the range [0, 10^4].
 *   -10^5 <= Node.val <= 10^5
 *   pos is -1 or a valid index in the linked-list.
 * 
 * Follow up: 
 *   Can you solve it using O(1) (i.e. constant) memory?
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, Linked List, Two Pointers
 */
#include <iostream>
#include <unordered_set>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        unordered_set<ListNode*> list_node_set;

        while (head != nullptr)
        {
            if (list_node_set.count(head))
            {
                return head;
            }
            else
            {
                list_node_set.insert(head);
            }

            head = head->next;
        }

        return nullptr;
    }
};


int main()
{
    int val_list[] = {3, 2, 0, -4};
    ListNode* head = create_list(val_list, 4);
    head->next->next->next->next = head->next;

    Solution solution;
    ListNode* cycle = solution.detectCycle(head);
    
    cout << cycle->val << endl;

    return 0;
}

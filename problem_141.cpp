/**
 * 141. Linked List Cycle
 * 
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
 * Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 * Constraints:
 *   The number of the nodes in the list is in the range [0, 10^4].
 *   -10^5 <= Node.val <= 10^5
 *   pos is -1 or a valid index in the linked-list.
 * 
 * Follow up:
 *   Can you solve it using O(1) (i.e. constant) memory?
 * 
 * Difficulty: Easy
 * Related Topics: Hash Table, Linked List, Two Pointers
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        
        // Traverse the list with two pointers at different speed: a slow pointer and a fast pointer.
        ListNode* slow = head;
        ListNode* fast = head->next;

        // If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};


int main()
{
    int val_list[] = {3, 2, 0, -4};
    ListNode* head = create_list(val_list, 4);
    head->next->next->next->next = head->next;

    Solution solution;
    bool has_cycle = solution.hasCycle(head);
    
    cout << has_cycle << endl;

    return 0;
}

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
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        // Traverse the list with two pointers at different speed: a slow pointer and a fast pointer.
        ListNode* slow = head;
        ListNode* fast = head->next;

        // If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }

        // l1 is the distance between the head node and the cycle entry node.
        // l2 is the distance between the cycle entry node and the meeting node.
        // c is the length of the cycle.
        // The slow pointer moves l1 + l2 steps, while the fast pointer moves l1 + l2 - 1 + nc steps.
        // 2 (l1 + l2) = l1 + l2 - 1 + nc
        // l1 = nc - 1 - l2 = (n - 1)c + (c - l2) - 1
        // After the slow pointer moves one more step, the head pointer and the slow pointer need the same steps to reach the cycle entry.
        slow = slow->next;

        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        
        return head;
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

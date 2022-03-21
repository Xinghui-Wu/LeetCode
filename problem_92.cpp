/**
 * 92. Reverse Linked List II
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * Constraints:
 *   The number of nodes in the list is n.
 *   1 <= n <= 500
 *   -500 <= Node.val <= 500
 *   1 <= left <= right <= n
 * 
 * Follow up:
 *   Could you do it in one pass?
 * 
 * Difficulty: Medium
 * Related Topics: Linked List
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* previous = dummy;

        int k = right - left + 1;

        while (--left)
        {
            previous = previous->next;
        }

        previous->next = reverseList(previous->next, k);
        
        return dummy->next;
    }


    ListNode* reverseList(ListNode* head, int k)
    {
        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* temp;
        
        while (--k)
        {
            temp = next->next;
            next->next = current;
            current = next;
            next = temp;
        }

        head->next = next;
        
        return current;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(val_list, 5);

    int left = 2;
    int right = 4;

    Solution solution;
    head = solution.reverseBetween(head, left, right);

    output_list(head);

    return 0;
}

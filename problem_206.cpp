/**
 * 206. Reverse Linked List
 * 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * Constraints:
 *   The number of nodes in the list is the range [0, 5000].
 *   -5000 <= Node.val <= 5000
 * 
 * Follow up:
 *   A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* temp;
        
        while (next != nullptr)
        {
            temp = next->next;
            next->next = current;
            current = next;
            next = temp;
        }

        head->next = nullptr;
        
        return current;
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    head = solution.reverseList(head);

    output_list(head);

    return 0;
}

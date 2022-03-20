/**
 * 25. Reverse Nodes in k-Group
 * 
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 * 
 * Constraints:
 *   The number of nodes in the list is n.
 *   1 <= k <= n <= 5000
 *   0 <= Node.val <= 1000
 * 
 * Follow-up:
 *   Can you solve the problem in O(1) extra memory space?
 * 
 * Difficulty: Hard
 * Related Topics: Linked List, Recursion
 */
#include <iostream>
#include "node.h"

using namespace std;


struct ListNodeTriplet
{
    ListNode* head;
    ListNode* tail;
    ListNode* next_head;
};


class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int length = get_length(head);
        int num_groups = length / k;

        if (length < k)
        {
            return head;
        }

        ListNodeTriplet triplet1 = reverseList(head, k);
        ListNodeTriplet triplet2 = triplet1;

        head = triplet1.head;

        for (int i = 1; i < num_groups; i++)
        {
            triplet2 = reverseList(triplet1.next_head, k);
            triplet1.tail->next = triplet2.head;
            triplet1 = triplet2;
        }

        triplet2.tail->next = triplet2.next_head;

        return head;
    }


    int get_length(ListNode* head)
    {
        int length = 0;

        while (head != nullptr)
        {
            length++;
            head = head->next;
        }
        
        return length;
    }


    ListNodeTriplet reverseList(ListNode* head, int k)
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

        head->next = nullptr;
        
        return {current, head, next};
    }
};


int main()
{
    int val_list[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    head = solution.reverseKGroup(head, 3);

    output_list(head);

    return 0;
}

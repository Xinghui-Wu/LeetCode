/**
 * 148. Sort List
 * 
 * Given the head of a linked list, return the list after sorting it in ascending order.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [0, 5 * 10^4].
 *   -10^5 <= Node.val <= 10^5
 * 
 * Follow up: 
 *   Can you sort the linked list in O(nlogn) time and O(1) memory (i.e. constant space)?
 * 
 * Difficulty: Medium
 * Related Topics: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* current = head;

        // Count the number of nodes in the list.
        int length = 0;
        
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }

        ListNode* dummy = new ListNode(0, head);
        // The head of the first splitted sublist.
        ListNode* left;
        // The head of the second splitted sublist.
        ListNode* right;
        // The tail of the sorted sublist.
        ListNode* tail;

        // Iteratively split the list into sublists of size 1, 2, 4, 8 and so on until the length.
        for (int size = 1; size < length; size <<= 1)
        {
            tail = dummy;
            current = dummy->next;

            while (current != nullptr)
            {
                left = current;
                right = split(left, size);
                current = split(right, size);
                tail = merge(left, right, tail);
            }
        }
        
        return dummy->next;
    }


    /**
     * Divide the linked list into two lists.
     * The first list contains first n nodes.
     * Return the head of the second list.
     */
    ListNode* split(ListNode* head, int size)
    {
        for (int i = 1; i < size && head != nullptr; i++)
        {
            head = head->next;
        }

        if (head == nullptr)
        {
            return nullptr;
        }
        
		ListNode* second = head->next;
		head->next = nullptr;
		
        return second;
    }


    /**
     * Merge two sorted lists.
     * Append the merged sorted linked list to the head node.
     * Return the tail of the merged sorted linked list.
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head)
    {
        ListNode* current = head;

        // Merge the two input sorted linked lists while neither of l1 and l2 is nullptr.
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        // If either l1 or l2 is not nullptr now, connect it to the current pointer.
        if (l1 != nullptr)
        {
            current->next = l1;
        }
        else if (l2 != nullptr)
        {
            current->next = l2;
        }

        // Find the tail pointer.
        while (current->next != nullptr)
        {
            current = current->next;
        }

        return current;
    }
};


int main()
{
    int val_list[] = {10, 1, 30, 2, 5};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    head = solution.sortList(head);

    output_list(head);

    return 0;
}

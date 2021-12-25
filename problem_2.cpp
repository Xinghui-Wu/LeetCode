/**
 * 2. Add Two Numbers
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Constraints:
 *   The number of nodes in each linked list is in the range [1, 100].
 *   0 <= Node.val <= 9
 *   It is guaranteed that the list represents a number that does not have leading zeros.
 * 
 * Difficulty: Medium
 * Related Topics: Linked List, Math, Recursion
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sum = new ListNode();
        ListNode* current = sum;
        ListNode* temp = nullptr;
        
        int digit_sum;
        int carry = 0;

        // Add l1 and l2 digit by digit.
        while (l1 != nullptr && l2 != nullptr)
        {
            digit_sum = l1->val + l2->val + carry;

            if (digit_sum <= 9)
            {
                carry = 0;
            }
            else
            {
                digit_sum -= 10;
                carry = 1;
            }

            current->next = new ListNode();
            current = current->next;
            current->val = digit_sum;
            
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr)
        {
            temp = l1;
        }
        else if (l2 != nullptr)
        {
            temp = l2;
        }

        // Add the rest of l1 or l2.
        while (temp != nullptr)
        {
            digit_sum = temp->val + carry;

            if (digit_sum <= 9)
            {
                carry = 0;
            }
            else
            {
                digit_sum -= 10;
                carry = 1;
            }
            
            current->next = new ListNode();
            current = current->next;
            current->val = digit_sum;

            temp = temp->next;
        }

        if (temp == nullptr && carry == 1)
        {
            current->next = new ListNode(1);
        }
        
        return sum->next;
    }
};


int main()
{
    int l1_val_list[] = {9, 9, 9, 9, 9, 9, 9};
    int l2_val_list[] = {9, 9, 9, 9};
    ListNode* l1 = create_list(l1_val_list, 7);
    ListNode* l2 = create_list(l2_val_list, 4);
    
    Solution solution;
    ListNode* sum = solution.addTwoNumbers(l1, l2);

    output_list(sum);

    return 0;
}

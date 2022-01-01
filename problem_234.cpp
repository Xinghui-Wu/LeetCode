/**
 * 234. Palindrome Linked List
 * 
 * Given the head of a singly linked list, return true if it is a palindrome.
 * 
 * Constraints:
 *   The number of nodes in the list is in the range [1, 10^5].
 *   0 <= Node.val <= 9
 * 
 * Difficulty: Easy
 * Related Topics: Linked List, Two Pointers, Stack, Recursion
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* mid = reverse_list(get_middle(head));

        ListNode* current_a = head;
        ListNode* current_b = mid;

        while (current_b != nullptr)
        {
            if (current_a->val != current_b->val)
            {
                return false;
            }
            
            current_a = current_a->next;
            current_b = current_b->next;
        }

        return true;
    }


    ListNode* get_middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }


    ListNode* reverse_list(ListNode* head)
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
    int val_list[] = {1, 2, 3, 2, 1};
    ListNode* head = create_list(val_list, 5);

    Solution solution;
    bool is_palindrome = solution.isPalindrome(head);

    cout << is_palindrome << endl;

    return 0;
}

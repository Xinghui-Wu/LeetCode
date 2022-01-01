/**
 * 328. Odd Even Linked List
 * 
 * Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
 * The first node is considered odd, and the second node is even, and so on.
 * Note that the relative order inside both the even and odd groups should remain as it was in the input.
 * You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 * 
 * Constraints:
 *   n == number of nodes in the linked list
 *   0 <= n <= 10^4
 *   -10^6 <= Node.val <= 10^6
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
    ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* even_head = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        
        while (odd->next != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = even_head;
        
        return head;
    }
};


int main()
{
    int val_list[] = {2, 1, 3, 5, 6, 4};
    ListNode* head = create_list(val_list, 6);

    Solution solution;
    head = solution.oddEvenList(head);

    output_list(head);

    return 0;
}

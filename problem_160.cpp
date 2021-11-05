/**
 * 160. Intersection of Two Linked Lists
 * 
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
 * If the two linked lists have no intersection at all, return null.
 * The test cases are generated such that there are no cycles anywhere in the entire linked structure.
 * Note that the linked lists must retain their original structure after the function returns.
 * 
 * Custom Judge:
 *   The inputs to the judge are given as follows (your program is not given these inputs):
 *     intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
 *     listA - The first linked list.
 *     listB - The second linked list.
 *     skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
 *     skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
 *   The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program.
 *   If you correctly return the intersected node, then your solution will be accepted.
 * 
 * Constraints:
 *   The number of nodes of listA is in the m.
 *   The number of nodes of listB is in the n.
 *   0 <= m, n <= 3 * 10^4
 *   1 <= Node.val <= 10^5
 *   0 <= skipA <= m
 *   0 <= skipB <= n
 *   intersectVal is 0 if listA and listB do not intersect.
 *   intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 * 
 * Follow up:
 *   Could you write a solution that runs in O(n) time and use only O(1) memory?
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        
        // Maintain two pointers initialized at the head of A and B respectively.
        ListNode* current_a = headA;
        ListNode* current_b = headB;

        // Let the two pointers both traverse through the lists, one node at a time.
        // When one pointer reaches the end of a list, redirect it to the head of another list.
        // After traversing the two lists twice, the intersection will be found (it can be the tail nullptr).
        while (current_a != current_b)
        {
            if (current_a != nullptr)
            {
                current_a = current_a->next;
            }
            else
            {
                current_a = headB;
            }

            if (current_b != nullptr)
            {
                current_b = current_b->next;
            }
            else
            {
                current_b = headA;
            }
        }

        return current_a;
    }
};


int main()
{
    int a_val_list[] = {4, 1};
    int b_val_list[] = {5, 6, 1};
    int intersection_val_list[] = {8, 4, 5};

    ListNode* headA = create_list(a_val_list, 2);
    ListNode* headB = create_list(b_val_list, 3);
    ListNode* intersection = create_list(intersection_val_list, 3);
    
    headA->next->next = intersection;
    headB->next->next->next = intersection;

    Solution solution;
    ListNode* intersection_node = solution.getIntersectionNode(headA, headB);

    cout << intersection_node->val << endl;

    return 0;
}

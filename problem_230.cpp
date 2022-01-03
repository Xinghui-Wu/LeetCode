/**
 * 230. Kth Smallest Element in a BST
 * 
 * Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 * 
 * Constraints:
 *   The number of nodes in the tree is n.
 *   1 <= k <= n <= 10^4
 *   0 <= Node.val <= 10^4
 * 
 * Follow up:
 *   If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include <vector>
#include <stack>
#include "node.h"

using namespace std;


class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> tree_node_stack;

        TreeNode* current = root;

        // Use a DFS stack to do the binary tree inorder traversal.
        // The inorder traversal of a BST should be a sorted list.
        while (current != nullptr || !tree_node_stack.empty())
        {
            while (current != nullptr)
            {
                tree_node_stack.push(current);
                current = current->left;
            }
            
            current = tree_node_stack.top();
            tree_node_stack.pop();

            if (k-- == 1)
            {
                return current->val;
            }
            
            current = current->right;
        }

        return 0;
    }
};


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;

    Solution solution;
    int k_th_smallest = solution.kthSmallest(root, k);

    cout << k_th_smallest << endl;

    return 0;
}

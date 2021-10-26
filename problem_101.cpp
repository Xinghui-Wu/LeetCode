/**
 * 101. Symmetric Tree
 * 
 * Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 1000].
 *   -100 <= Node.val <= 100
 * 
 * Follow up:
 *   Could you solve it both recursively and iteratively?
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        queue<TreeNode*> left_tree_node_queue;
        left_tree_node_queue.push(root);

        queue<TreeNode*> right_tree_node_queue;
        right_tree_node_queue.push(root);

        TreeNode* left_current;
        TreeNode* right_current;

        // Breadth-First Search with Queue
        while (!left_tree_node_queue.empty() && !right_tree_node_queue.empty())
        {
            left_current = left_tree_node_queue.front();
            left_tree_node_queue.pop();
            
            right_current = right_tree_node_queue.front();
            right_tree_node_queue.pop();

            // Check whether the values of the two nodes are the same.
            if (left_current->val != right_current->val)
            {
                return false;
            }

            // Check the left child of the left node and the right child of the right node.
            if ((left_current->left == nullptr) != (right_current->right == nullptr))
            {
                return false;
            }
            if (left_current->left != nullptr && right_current->right != nullptr)
            {
                left_tree_node_queue.push(left_current->left);
                right_tree_node_queue.push(right_current->right);
            }

            // Check the right child of the left node and the left child of the right node.
            if ((left_current->right == nullptr) != (right_current->left == nullptr))
            {
                return false;
            }
            if (left_current->right != nullptr && right_current->left != nullptr)
            {
                left_tree_node_queue.push(left_current->right);
                right_tree_node_queue.push(right_current->left);
            }
        }

        return true;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool is_symmetric = solution.isSymmetric(root);

    cout << is_symmetric << endl;

    return 0;
}

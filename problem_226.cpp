/**
 * 226. Invert Binary Tree
 * 
 * Given the root of a binary tree, invert the tree, and return its root.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 100].
 *   -100 <= Node.val <= 100
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return root;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};


int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;
    root = solution.invertTree(root);

    output_level_order_traversal(root);

    return 0;
}

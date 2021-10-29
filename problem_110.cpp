/**
 * 110. Balanced Binary Tree
 * 
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as: a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 5000].
 *   -10^4 <= Node.val <= 10^4
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
private:
    bool is_balanced;

public:
    bool isBalanced(TreeNode* root)
    {
        is_balanced = true;

        get_depth(root);

        return is_balanced;
    }


    int get_depth(TreeNode* root)
    {
        // If there already exists an unbalanced subtree, return 0 directly to avoid unnecessary recursion.
        if (!is_balanced || root == nullptr)
        {
            return 0;
        }

        int left_subtree_depth = get_depth(root->left);
        int right_subtree_depth = get_depth(root->right);

        if (abs(left_subtree_depth - right_subtree_depth) > 1)
        {
            is_balanced = false;
        }

        return max(left_subtree_depth, right_subtree_depth) + 1;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(8);

    Solution solution;
    bool is_balanced = solution.isBalanced(root);

    cout << is_balanced << endl;

    return 0;
}

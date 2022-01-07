/**
 * 236. Lowest Common Ancestor of a Binary Tree
 * 
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [2, 10^5].
 *   -10^9 <= Node.val <= 10^9
 *   All Node.val are unique.
 *   p != q
 *   p and q will exist in the tree.
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // If either p or q is found, return it.
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        // Search the left and right subtrees for p and q.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
        {
            return right;
        }
        else if (right == nullptr)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;
    TreeNode* q = root->left->right;

    Solution solution;
    TreeNode* ancestor = solution.lowestCommonAncestor(root, p, q);

    cout << ancestor->val << endl;

    return 0;
}

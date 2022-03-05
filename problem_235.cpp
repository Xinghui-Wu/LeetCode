/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [2, 10^5].
 *   -10^9 <= Node.val <= 10^9
 *   All Node.val are unique.
 *   p != q
 *   p and q will exist in the BST.
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // Narrow down the search space to the left or right subtree.
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    Solution solution;
    TreeNode* ancestor = solution.lowestCommonAncestor(root, p, q);

    cout << ancestor->val << endl;

    return 0;
}

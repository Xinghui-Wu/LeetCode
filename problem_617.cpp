/**
 * 617. Merge Two Binary Trees
 * 
 * You are given two binary trees root1 and root2.
 * Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 * You need to merge the two trees into a new binary tree.
 * The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of the new tree.
 * Return the merged tree.
 * 
 * Note:
 *   The merging process must start from the root nodes of both trees.
 * 
 * Constraints:
 *   The number of nodes in both trees is in the range [0, 2000].
 *   -10^4 <= Node.val <= 10^4
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr)
        {
            return root2;
        }

        if (root2 == nullptr)
        {
            return root1;
        }
        
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        
        return root;
    }
};


int main()
{
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution solution;
    TreeNode* root = solution.mergeTrees(root1, root2);

    output_level_order_traversal(root);

    return 0;
}

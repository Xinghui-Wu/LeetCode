/**
 * 538. Convert BST to Greater Tree
 * 
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
 * As a reminder, a binary search tree is a tree that satisfies these constraints:
 *   The left subtree of a node contains only nodes with keys less than the node's key.
 *   The right subtree of a node contains only nodes with keys greater than the node's key.
 *   Both the left and right subtrees must also be binary search trees.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 10^4].
 *   -10^4 <= Node.val <= 10^4
 *   All the values in the tree are unique.
 *   root is guaranteed to be a valid binary search tree.
 * 
 * Note:
 *   This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;

        dfs(root, sum);
        
        return root;
    }


    void dfs(TreeNode* root, int& sum)
    {
        if (root != nullptr)
        {
            dfs(root->right, sum);

            sum += root->val;
            root->val = sum;

            dfs(root->left, sum);
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(8);

    Solution solution;
    root = solution.convertBST(root);

    output_level_order_traversal(root);

    return 0;
}

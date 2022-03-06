/**
 * 701. Insert into a Binary Search Tree
 * 
 * You are given the root node of a binary search tree (BST) and a value to insert into the tree.
 * Return the root node of the BST after the insertion.
 * It is guaranteed that the new value does not exist in the original BST.
 * Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion.
 * You can return any of them.
 * 
 * Constraints:
 *   The number of nodes in the tree will be in the range [0, 10^4].
 *   -10^8 <= Node.val <= 10^8
 *   All the values Node.val are unique.
 *   -10^8 <= val <= 10^8
 *   It's guaranteed that val does not exist in the original BST.
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

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

    int val = 5;

    Solution solution;
    root = solution.insertIntoBST(root, val);

    output_level_order_traversal(root);

    return 0;
}

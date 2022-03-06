/**
 * 450. Delete Node in a BST
 * 
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 * Return the root node reference (possibly updated) of the BST.
 * Basically, the deletion can be divided into two stages:
 *   1. Search for a node to remove.
 *   2. If the node is found, delete the node.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 10^4].
 *   -10^5 <= Node.val <= 10^5
 *   Each node has a unique value.
 *   root is a valid binary search tree.
 *   -10^5 <= key <= 10^5
 * 
 * Follow up:
 *   Could you solve it with time complexity O(height of tree)?
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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // If the node is a leaf.
            if (root->left == nullptr && root->right == nullptr)
            {
                root = nullptr;
            }
            else if (root->right != nullptr)
            {
                root->val = get_successor(root)->val;
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                root->val = get_predecessor(root)->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        
        return root;
    }


    TreeNode* get_successor(TreeNode* root)
    {
        root = root->right;

        while (root->left != nullptr)
        {
            root = root->left;
        }
        
        return root;
    }


    TreeNode* get_predecessor(TreeNode* root)
    {
        root = root->left;

        while (root->right != nullptr)
        {
            root = root->right;
        }
        
        return root;
    }
};


int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int key = 3;

    Solution solution;
    root = solution.deleteNode(root, key);

    output_level_order_traversal(root);

    return 0;
}

/**
 * 700. Search in a Binary Search Tree
 * 
 * You are given the root of a binary search tree (BST) and an integer val.
 * Find the node in the BST that the node's value equals val and return the subtree rooted with that node.
 * If such a node does not exist, return null.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 5000].
 *   1 <= Node.val <= 10^7
 *   root is a binary search tree.
 *   1 <= val <= 10^7
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        while (root != nullptr)
        {
            if (root->val == val)
            {
                return root;
            }
            else if (root->val > val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        
        return nullptr;
    }
};


int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    Solution solution;
    TreeNode* node = solution.searchBST(root, val);

    cout << node->val << endl;

    return 0;
}

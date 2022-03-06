/**
 * 669. Trim a Binary Search Tree
 * 
 * Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high].
 * Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant).
 * It can be proven that there is a unique answer.
 * Return the root of the trimmed binary search tree.
 * Note that the root may change depending on the given bounds.
 * 
 * Constraints:
 *   The number of nodes in the tree in the range [1, 10^4].
 *   0 <= Node.val <= 10^4
 *   The value of each node in the tree is unique.
 *   root is guaranteed to be a valid binary search tree.
 *   0 <= low <= high <= 10^4
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
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val < low)
        {
            return trimBST(root->right, low, high);
        }

        if (root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    int low = 1;
    int high = 3;

    Solution solution;
    root = solution.trimBST(root, low, high);

    output_level_order_traversal(root);

    return 0;
}

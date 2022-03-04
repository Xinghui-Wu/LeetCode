/**
 * 222. Count Complete Tree Nodes
 * 
 * Given the root of a complete binary tree, return the number of the nodes in the tree.
 * According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
 * It can have between 1 and 2h nodes inclusive at the last level h.
 * Design an algorithm that runs in less than O(n) time complexity.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 5 * 10^4].
 *   0 <= Node.val <= 5 * 10^4
 *   The tree is guaranteed to be complete.
 * 
 * Difficulty: Medium
 * Related Topics: Binary Search, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int countNodes(TreeNode* root)
    {
        return dfs(root);
    }


    int dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        
        return dfs(root->left) + dfs(root->right) + 1;
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

    Solution solution;
    int count = solution.countNodes(root);

    cout << count << endl;

    return 0;
}

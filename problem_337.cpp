/**
 * 337. House Robber III
 * 
 * The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called root.
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that all houses in this place form a binary tree.
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 10^4].
 *   0 <= Node.val <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Dynamic Programming, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int rob(TreeNode* root)
    {
        pair<int, int> money = rob_tree(root);

        return max(money.first, money.second);
    }


    pair<int, int> rob_tree(TreeNode* root)
    {
        pair<int, int> dp = {0, 0};

        if (root == nullptr)
        {
            return dp;
        }
        
        pair<int, int> rob_left = rob_tree(root->left);
        pair<int, int> rob_right = rob_tree(root->right);

        dp.first = max(rob_left.first, rob_left.second) + max(rob_right.first, rob_right.second);
        dp.second = rob_left.first + rob_right.first + root->val;

        return dp;
    }
};


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution solution;
    int money = solution.rob(root);

    cout << money << endl;
    
    return 0;
}

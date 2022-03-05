/**
 * 530. Minimum Absolute Difference in BST
 * 
 * Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [2, 10^4].
 *   0 <= Node.val <= 10^5
 * 
 * Note:
 *   This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int getMinimumDifference(TreeNode* root)
    {
        int min_difference = 100000;

        TreeNode* previous = nullptr;

        dfs(root, previous, min_difference);
        
        return min_difference;
    }


    void dfs(TreeNode* current, TreeNode*& previous, int& min_difference)
    {
        if (current != nullptr)
        {
            dfs(current->left, previous, min_difference);

            if (previous != nullptr)
            {
                min_difference = min(min_difference, current->val - previous->val);
            }

            previous = current;
            
            dfs(current->right, previous, min_difference);
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    int min_difference = solution.getMinimumDifference(root);

    cout << min_difference << endl;

    return 0;
}

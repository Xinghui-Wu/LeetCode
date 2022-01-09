/**
 * 124. Binary Tree Maximum Path Sum
 * 
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
 * A node can only appear in the sequence at most once.
 * Note that the path does not need to pass through the root.
 * The path sum of a path is the sum of the node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 3 * 10^4].
 *   -1000 <= Node.val <= 1000
 * 
 * Difficulty: Hard
 * Related Topics: Dynamic Programming, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
private:
    int max_path_sum;

public:
    int maxPathSum(TreeNode* root)
    {
        max_path_sum = INT32_MIN;

        max_gain(root);

        return max_path_sum;
    }


    /**
     * Calculate the maximum gain value of a node in the binary tree.
     * Find a path starting from the node in the subtree with the node as the root node.
     * Make the sum of the node values on the path the largest.
     */
    int max_gain(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_gain = max(max_gain(root->left), 0);
        int right_gain = max(max_gain(root->right), 0);
        int root_gain = root->val + left_gain + right_gain;

        if (root_gain > max_path_sum)
        {
            max_path_sum = root_gain;
        }
        
        return root->val + max(left_gain, right_gain);
    }
};


int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int max_path_sum = solution.maxPathSum(root);

    cout << max_path_sum << endl;

    return 0;
}

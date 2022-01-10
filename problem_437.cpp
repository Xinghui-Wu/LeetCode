/**
 * 437. Path Sum III
 * 
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 1000].
 *   -10^9 <= Node.val <= 10^9
 *   -1000 <= targetSum <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include <unordered_map>
#include "node.h"

using namespace std;


class Solution
{
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<long, int> prefix_sum;
        prefix_sum[0] = 1;

        int num_paths = dfs(root, prefix_sum, 0, targetSum);

        return num_paths;
    }


    /**
     * Traverse the binary tree with DFS recursively.
     * Save the prefix sum of the path starting from the root node and ending at the current node.
     * Based on the current and historical prefix sum records, count the number of paths.
     */
    int dfs(TreeNode* current, unordered_map<long, int>& prefix_sum, long current_sum, int targetSum)
    {
        if (current == nullptr)
        {
            return 0;
        }

        // Update the prefix sum of the current node.
        current_sum += current->val;

        // Use the difference between curren prefix sum and target sum to count the paths ending at the current node.
        int num_paths = prefix_sum[current_sum - targetSum];

        // Update the hashmap with the current prefix sum.
        prefix_sum[current_sum]++;

        // Search the left and right subtrees.
        num_paths += dfs(current->left, prefix_sum, current_sum, targetSum);
        num_paths += dfs(current->right, prefix_sum, current_sum, targetSum);
        
        // Backtrack to the parent node.
        prefix_sum[current_sum]--;

        return num_paths;
    }
};


int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int num_paths = solution.pathSum(root, 8);

    cout << num_paths << endl;

    return 0;
}

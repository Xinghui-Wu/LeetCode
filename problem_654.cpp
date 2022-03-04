/**
 * 654. Maximum Binary Tree
 * 
 * You are given an integer array nums with no duplicates.
 * A maximum binary tree can be built recursively from nums using the following algorithm:
 *   1. Create a root node whose value is the maximum value in nums.
 *   2. Recursively build the left subtree on the subarray prefix to the left of the maximum value.
 *   3. Recursively build the right subtree on the subarray suffix to the right of the maximum value.
 * Return the maximum binary tree built from nums.
 * 
 * Constraints:
 *   1 <= nums.length <= 1000
 *   0 <= nums[i] <= 1000
 *   All integers in nums are unique.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Divide and Conquer, Stack, Tree, Monotonic Stack, Binary Tree
 */
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return build_subtree(nums, 0, nums.size() - 1);
    }


    TreeNode* build_subtree(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        
        int max_index = left;

        for (int i = left + 1; i <= right; i++)
        {
            if (nums[i] > nums[max_index])
            {
                max_index = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = build_subtree(nums, left, max_index - 1);
        root->right = build_subtree(nums, max_index + 1, right);

        return root;
    }
};


int main()
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution solution;
    TreeNode* root = solution.constructMaximumBinaryTree(nums);

    output_level_order_traversal(root);

    return 0;
}

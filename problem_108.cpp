/**
 * 108. Convert Sorted Array to Binary Search Tree
 * 
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 *   nums is sorted in a strictly increasing order.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        TreeNode* root = get_bst_node(nums, 0, nums.size() - 1);

        return root;
    }


    TreeNode* get_bst_node(vector<int>& nums, int left, int right)
    {
        // Calculate the median index of the array within the specified range.
        int mid = (left + right) / 2;

        // Generate a tree node with the median as its value.
        TreeNode* tree_node = new TreeNode(nums[mid]);

        // Divide and Conquer
        if(left < mid)
        {
            tree_node->left = get_bst_node(nums, left, mid - 1);
        }
        if (mid < right)
        {
            tree_node->right = get_bst_node(nums, mid + 1, right);
        }

        return tree_node;
    }


    /**
     * Output the tree node values level by level.
     * This function is adapted from the solution to Problem 107.
     */
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> level_order_val_list;

        if (root == nullptr)
        {
            return level_order_val_list;
        }
        
        queue<TreeNode*> tree_node_queue;
        tree_node_queue.push(root);

        TreeNode* current;
        int num_level_tree_nodes;

        // Breadth-First Search with Queue
        while (!tree_node_queue.empty())
        {
            // Expand the current vector when going down to the next level.
            vector<int> level_val_list;
            
            num_level_tree_nodes = tree_node_queue.size();

            // All tree nodes in the current queue are from the same level.
            for (size_t i = 0; i < num_level_tree_nodes; i++)
            {
                current = tree_node_queue.front();
                tree_node_queue.pop();

                level_val_list.push_back(current->val);

                if (current->left != nullptr)
                {
                    tree_node_queue.push(current->left);
                }
                if (current->right != nullptr)
                {
                    tree_node_queue.push(current->right);
                }
            }

            level_order_val_list.push_back(level_val_list);
        }

        return level_order_val_list;
    }
};


int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);
    vector<vector<int>> level_order_val_list = solution.levelOrder(root);

    for (size_t i = 0; i < level_order_val_list.size(); i++)
    {
        for (size_t j = 0; j < level_order_val_list[i].size(); j++)
        {
            cout << level_order_val_list[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}

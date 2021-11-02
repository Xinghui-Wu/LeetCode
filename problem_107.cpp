/**
 * 107. Binary Tree Level Order Traversal II
 * 
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 2000].
 *   -1000 <= Node.val <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> level_order_val_list;

        if (root == nullptr)
        {
            return level_order_val_list;
        }
        
        queue<TreeNode*> tree_node_queue;
        tree_node_queue.push(root);

        queue<int> depth_queue;
        depth_queue.push(1);

        TreeNode* current;
        int current_depth;

        // Breadth-First Search with Queue
        while (!tree_node_queue.empty())
        {
            current = tree_node_queue.front();
            tree_node_queue.pop();

            current_depth = depth_queue.front();
            depth_queue.pop();

            // Expand the current vector when going down to the next level.
            if (current_depth > level_order_val_list.size())
            {
                vector<int> level_val_list;
                level_order_val_list.insert(level_order_val_list.begin(), level_val_list);
            }
            
            level_order_val_list[0].push_back(current->val);

            if (current->left != nullptr)
            {
                tree_node_queue.push(current->left);
                depth_queue.push(current_depth + 1);
            }
            if (current->right != nullptr)
            {
                tree_node_queue.push(current->right);
                depth_queue.push(current_depth + 1);
            }
        }

        return level_order_val_list;
    }
};


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> level_order_val_list = solution.levelOrderBottom(root);

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

/**
 * 102. Binary Tree Level Order Traversal
 * 
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
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
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
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

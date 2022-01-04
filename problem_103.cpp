/**
 * 103. Binary Tree Zigzag Level Order Traversal
 * 
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 2000].
 *   -100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
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
        bool left_to_right = true;

        // Breadth-First Search with Queue
        while (!tree_node_queue.empty())
        {
            num_level_tree_nodes = tree_node_queue.size();
            
            // Expand the current vector when going down to the next level.
            vector<int> level_val_list(num_level_tree_nodes);

            // All tree nodes in the current queue are from the same level.
            for (size_t i = 0; i < num_level_tree_nodes; i++)
            {
                current = tree_node_queue.front();
                tree_node_queue.pop();

                // level_val_list.push_back(current->val);
                if (left_to_right)
                {
                    level_val_list[i] = current->val;
                }
                else
                {
                    level_val_list[num_level_tree_nodes - 1 - i] = current->val;
                }

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

            left_to_right = !left_to_right;
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
    vector<vector<int>> level_order_val_list = solution.zigzagLevelOrder(root);

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

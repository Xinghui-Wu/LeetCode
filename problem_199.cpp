/**
 * 199. Binary Tree Right Side View
 * 
 * Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 100].
 *   -100 <= Node.val <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<vector<int>> level_order_val_list = levelOrder(root);
        vector<int> level_val_list;

        vector<int> right_side_view(level_order_val_list.size());

        for (size_t i = 0; i < level_order_val_list.size(); i++)
        {
            level_val_list = level_order_val_list[i];
            right_side_view[i] = level_val_list[level_val_list.size() - 1];
        }

        return right_side_view;
    }


    /**
     * Binary Tree Level Order Traversal
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
            num_level_tree_nodes = tree_node_queue.size();

            // Expand the current vector when going down to the next level.
            vector<int> level_val_list(num_level_tree_nodes);

            // All tree nodes in the current queue are from the same level.
            for (size_t i = 0; i < num_level_tree_nodes; i++)
            {
                current = tree_node_queue.front();
                tree_node_queue.pop();

                level_val_list[i] = current->val;

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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> right_side_view = solution.rightSideView(root);

    for (size_t i = 0; i < right_side_view.size(); i++)
    {
        cout << right_side_view[i] << endl;
    }
    
    return 0;
}

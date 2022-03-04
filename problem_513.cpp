/**
 * 513. Find Bottom Left Tree Value
 * 
 * Given the root of a binary tree, return the leftmost value in the last row of the tree.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 10^4].
 *   -2^31 <= Node.val <= 2^31 - 1
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    int findBottomLeftValue(TreeNode* root)
    {
        int bottom_left;

        queue<TreeNode*> tree_node_queue;
        tree_node_queue.push(root);

        TreeNode* current;
        int num_level_tree_nodes;

        while (!tree_node_queue.empty())
        {
            bottom_left = tree_node_queue.front()->val;
            
            num_level_tree_nodes = tree_node_queue.size();

            // All tree nodes in the current queue are from the same level.
            for (size_t i = 0; i < num_level_tree_nodes; i++)
            {
                current = tree_node_queue.front();
                tree_node_queue.pop();

                if (current->left != nullptr)
                {
                    tree_node_queue.push(current->left);
                }
                if (current->right != nullptr)
                {
                    tree_node_queue.push(current->right);
                }
            }
        }

        return bottom_left;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    Solution solution;
    int bottom_left = solution.findBottomLeftValue(root);

    cout << bottom_left << endl;

    return 0;
}

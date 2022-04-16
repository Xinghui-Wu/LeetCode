/**
 * 662. Maximum Width of Binary Tree
 * 
 * Given the root of a binary tree, return the maximum width of the given tree.
 * The maximum width of a tree is the maximum width among all levels.
 * The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
 * It is guaranteed that the answer will in the range of a 32-bit signed integer.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 3000].
 *   -100 <= Node.val <= 100
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
    int widthOfBinaryTree(TreeNode* root)
    {
        size_t width = 0;

        // Save the tree nodes and their positions as in a complete binary tree.
        queue<pair<TreeNode*, size_t>> tree_node_queue;
        tree_node_queue.push({root, 0});
        
        pair<TreeNode*, size_t> current;
        size_t num_level_tree_nodes;
        size_t level_start_index;
        size_t level_end_index;

        while (!tree_node_queue.empty())
        {
            num_level_tree_nodes = tree_node_queue.size();
            level_start_index = -1;

            for (size_t i = 0; i < num_level_tree_nodes; i++)
            {
                current = tree_node_queue.front();
                tree_node_queue.pop();

                if (level_start_index == -1)
                {
                    level_start_index = current.second;
                }
                
                level_end_index = current.second;

                if (current.first->left != nullptr)
                {
                    tree_node_queue.push({current.first->left, 2 * current.second + 1});
                }
                if (current.first->right != nullptr)
                {
                    tree_node_queue.push({current.first->right, 2 * current.second + 2});
                }
            }

            width = max(width, level_end_index - level_start_index + 1);
        }

        return width;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution solution;
    int width = solution.widthOfBinaryTree(root);

    cout << width << endl;

    return 0;
}

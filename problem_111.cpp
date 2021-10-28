/**
 * 111. Minimum Depth of Binary Tree
 * 
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 * Note:
 *   A leaf is a node with no children.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 10^5].
 *   -1000 <= Node.val <= 1000
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
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

            if (current->left == nullptr && current->right == nullptr)
            {
                return current_depth;
            }

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

        return 0;
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
    int min_depth = solution.minDepth(root);

    cout << min_depth << endl;

    return 0;
}

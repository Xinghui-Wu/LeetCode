/**
 * 104. Maximum Depth of Binary Tree
 * 
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 10^4].
 *   -100 <= Node.val <= 100
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <stack>
#include "node.h"

using namespace std;


class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int max_depth = 1;

        stack<TreeNode*> tree_node_stack;
        tree_node_stack.push(root);

        stack<int> depth_stack;
        depth_stack.push(1);

        TreeNode* current;
        int current_depth;

        // Depth-First Search with Stack
        while (!tree_node_stack.empty())
        {
            current = tree_node_stack.top();
            tree_node_stack.pop();

            current_depth = depth_stack.top();
            depth_stack.pop();

            if (current->right != nullptr)
            {
                tree_node_stack.push(current->right);
                depth_stack.push(current_depth + 1);
            }
            if (current->left != nullptr)
            {
                tree_node_stack.push(current->left);
                depth_stack.push(current_depth + 1);
            }
            
            if (current_depth > max_depth)
            {
                max_depth = current_depth;
            }
        }

        return max_depth;
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
    int max_depth = solution.maxDepth(root);

    cout << max_depth << endl;

    return 0;
}

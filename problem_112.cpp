/**
 * 112. Path Sum
 * 
 * Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 * A leaf is a node with no children.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 5000].
 *   -1000 <= Node.val <= 1000
 *   -1000 <= targetSum <= 1000
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include <stack>
#include "node.h"

using namespace std;


class Solution
{
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        stack<TreeNode*> tree_node_stack;
        tree_node_stack.push(root);

        stack<int> path_sum_stack;
        path_sum_stack.push(root->val);

        TreeNode* current;
        int current_path_sum;

        // Depth-First Search with Stack
        while (!tree_node_stack.empty())
        {
            current = tree_node_stack.top();
            tree_node_stack.pop();

            current_path_sum = path_sum_stack.top();
            path_sum_stack.pop();

            if (current->left == nullptr && current->right == nullptr && current_path_sum == targetSum)
            {
                return true;
            }

            if (current->right != nullptr)
            {
                tree_node_stack.push(current->right);
                path_sum_stack.push(current_path_sum + current->right->val);
            }
            if (current->left != nullptr)
            {
                tree_node_stack.push(current->left);
                path_sum_stack.push(current_path_sum + current->left->val);
            }
        }
        
        return false;
    }
};


int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    
    int targetSum = 22;

    Solution solution;
    bool has_path_sum = solution.hasPathSum(root, targetSum);

    cout << has_path_sum << endl;

    return 0;
}

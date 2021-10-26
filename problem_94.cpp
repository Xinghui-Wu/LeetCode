/**
 * 94. Binary Tree Inorder Traversal
 * 
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 100].
 *   -100 <= Node.val <= 100
 * 
 * Follow up:
 *   Recursive solution is trivial, could you do it iteratively?
 * 
 * Difficulty: Easy
 * Related Topics: Stack, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include <vector>
#include <stack>
#include "node.h"

using namespace std;


class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> inorder_val_list;

        stack<TreeNode*> tree_node_stack;
        TreeNode* current = root;

        while (current != nullptr || !tree_node_stack.empty())
        {
            while (current != nullptr)
            {
                tree_node_stack.push(current);
                current = current->left;
            }
            
            current = tree_node_stack.top();
            tree_node_stack.pop();

            inorder_val_list.push_back(current->val);
            
            current = current->right;
        }

        return inorder_val_list;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> inorder_val_list = solution.inorderTraversal(root);

    for (size_t i = 0; i < inorder_val_list.size(); i++)
    {
        cout << inorder_val_list[i] << endl;
    }

    return 0;
}

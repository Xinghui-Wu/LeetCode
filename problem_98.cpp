/**
 * 98. Validate Binary Search Tree
 * 
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 *   The left subtree of a node contains only nodes with keys less than the node's key.
 *   The right subtree of a node contains only nodes with keys greater than the node's key.
 *   Both the left and right subtrees must also be binary search trees.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 10^4].
 *   -2^31 <= Node.val <= 2^31 - 1
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include <vector>
#include <stack>
#include "node.h"

using namespace std;


class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        vector<int> inorder_val_list = inorderTraversal(root);

        // The inorder traversal of a BST should be a sorted list.
        for (size_t i = 1; i < inorder_val_list.size(); i++)
        {
            if (inorder_val_list[i] <= inorder_val_list[i - 1])
            {
                return false;
            }
        }

        return true;
    }

    
    /**
     * Binary Tree Inorder Traversal
     */
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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    Solution solution;
    bool is_valid_bst = solution.isValidBST(root);

    cout << is_valid_bst << endl;

    return 0;
}

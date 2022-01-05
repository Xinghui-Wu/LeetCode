/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 * 
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 * 
 * Constraints:
 *   1 <= preorder.length <= 3000
 *   postorder.length == inorder.length
 *   -3000 <= inorder[i], postorder[i] <= 3000
 *   inorder and postorder consist of unique values.
 *   Each value of postorder also appears in inorder.
 *   inorder is guaranteed to be the inorder traversal of the tree.
 *   postorder is guaranteed to be the postorder traversal of the tree.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include "node.h"

using namespace std;


class Solution
{
private:
    // Build a hashmap to record the relation of value and index for inorder.
    unordered_map<int, size_t> inorder_index_map;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        inorder_index_map.clear();

        for (size_t i = 0; i < inorder.size(); i++)
        {
            inorder_index_map.insert({inorder[i], i});
        }

        TreeNode* root = build_subtree(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);

        return root;
    }


    /**
     * To find the left and right subtrees, it will look for the root in inorder.
     * Everything on the left should be the left subtree, and everything on the right should be the right subtree.
     * Both subtrees can be constructed by making another recursion call.
     * Always use the last element in postorder to initialize a root.
     * Partition postorder based on the partition of inorder.
     */
    TreeNode* build_subtree(vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right)
    {
        if (inorder_left > inorder_right)
        {
            return nullptr;
        }
        
        // Select the element at the end of the postorder list as the root.
        TreeNode* root = new TreeNode(postorder[postorder_right]);

        // Locate the root value in inorder list.
        int inorder_index = inorder_index_map[root->val];
        int num_left = inorder_index - inorder_left;

        // Recursively build the left and right subtrees.
        root->left = build_subtree(postorder, inorder_left, inorder_index - 1, postorder_left, postorder_left + num_left - 1);
        root->right = build_subtree(postorder, inorder_index + 1, inorder_right, postorder_left + num_left, postorder_right - 1);

        return root;
    }
};


int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    output_level_order_traversal(root);
    
    return 0;
}

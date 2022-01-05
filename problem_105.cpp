/**
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * 
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 * 
 * Constraints:
 *   1 <= preorder.length <= 3000
 *   inorder.length == preorder.length
 *   -3000 <= preorder[i], inorder[i] <= 3000
 *   preorder and inorder consist of unique values.
 *   Each value of inorder also appears in preorder.
 *   preorder is guaranteed to be the preorder traversal of the tree.
 *   inorder is guaranteed to be the inorder traversal of the tree.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
private:
    // Build a hashmap to record the relation of value and index for inorder.
    unordered_map<int, size_t> inorder_index_map;
    // Keep track of the element that will be used to construct the root.
    int current_preorder;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        inorder_index_map.clear();

        for (size_t i = 0; i < inorder.size(); i++)
        {
            inorder_index_map.insert({inorder[i], i});
        }
        
        current_preorder = 0;

        TreeNode* root = build_subtree(preorder, 0, preorder.size() - 1);

        return root;
    }


    /**
     * To find the left and right subtrees, it will look for the root in inorder.
     * Everything on the left should be the left subtree, and everything on the right should be the right subtree.
     * Both subtrees can be constructed by making another recursion call.
     * Always use the next element in preorder to initialize a root.
     */
    TreeNode* build_subtree(vector<int>& preorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        
        // Select the element indexed by current_preorder as the root.
        TreeNode* root = new TreeNode(preorder[current_preorder++]);

        // Locate the element indexed by current_preorder in inorder list.
        int inorder_index = inorder_index_map[root->val];

        // Recursively build the left and right subtrees.
        root->left = build_subtree(preorder, left, inorder_index - 1);
        root->right = build_subtree(preorder, inorder_index + 1, right);

        return root;
    }
};


int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    output_level_order_traversal(root);
    
    return 0;
}

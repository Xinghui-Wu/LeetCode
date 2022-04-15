/**
 * 968. Binary Tree Cameras
 * 
 * You are given the root of a binary tree.
 * We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
 * Return the minimum number of cameras needed to monitor all nodes of the tree.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 1000].
 *   Node.val == 0
 * 
 * Difficulty: Hard
 * Related Topics: Dynamic Programming, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int minCameraCover(TreeNode* root)
    {
        int num_cameras = 0;

        if (dfs(root, num_cameras) == 0)
        {
            num_cameras++;
        }        

        return num_cameras;
    }


    int dfs(TreeNode* root, int& num_cameras)
    {
        // The nullptr node is regarded as being monitored (state 2).
        if (root == nullptr)
        {
            return 2;
        }
        
        // DFS the binary tree with the post-order traversal.
        int left = dfs(root->left, num_cameras);
        int right = dfs(root->right, num_cameras);

        // If the left and right children are both monitored (state 2), the root node is not monitored (state 0).
        if (left == 2 && right == 2)
        {
            return 0;
        }
        // If either the left child or the right child is not monitored, there is a camera at the root node (state 1).
        else if (left == 0 || right == 0)
        {
            num_cameras++;

            return 1;
        }
        // If either the left child or the right child has a camera, the root node is monitored (state 2).
        else
        {
            return 2;
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    Solution solution;
    int num_cameras = solution.minCameraCover(root);

    cout << num_cameras << endl;

    return 0;
}

/**
 * 1448. Count Good Nodes in Binary Tree
 * 
 * Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
 * Return the number of good nodes in the binary tree.
 * 
 * Constraints:
 *   The number of nodes in the binary tree is in the range [1, 10^5].
 *   Each node's value is between [-10^4, 10^4].
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int goodNodes(TreeNode* root)
    {
        int num_good_nodes = 0;

        dfs(root, num_good_nodes, -100000);

        return num_good_nodes;
    }

    
    void dfs(TreeNode* root, int& num_good_nodes, int path_max)
    {
        if (root == nullptr)
        {
            return;
        }

        // Compare the current node with the recorded maximum node value along the path from the root.
        if (root->val >= path_max)
        {
            num_good_nodes++;
            path_max = root->val;
        }
        
        dfs(root->left, num_good_nodes, path_max);
        dfs(root->right, num_good_nodes, path_max);
    }
};


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution solution;
    int num_good_nodes = solution.goodNodes(root);

    cout << num_good_nodes << endl;

    return 0;
}

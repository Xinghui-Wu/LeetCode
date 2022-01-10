/**
 * 113. Path Sum II
 * 
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
 * Each path should be returned as a list of the node values, not node references.
 * A root-to-leaf path is a path starting from the root and ending at any leaf node.
 * A leaf is a node with no children.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 5000].
 *   -1000 <= Node.val <= 1000
 *   -1000 <= targetSum <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Backtracking, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;


class Solution
{
private:
    vector<vector<int>> path_list;
    vector<int> path;

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        path_list.clear();
        path.clear();

        if (root == nullptr)
        {
            return path_list;
        }

        path.push_back(root->val);

        find_path(root, targetSum - root->val);

        return path_list;
    }


    /**
     * Traverse the binary tree with DFS recursively.
     * Backtrack to the previous status when one path is found.
     */
    void find_path(TreeNode* current, int targetSum)
    {
        // Reach a leaf node.
        if (current->left == nullptr && current->right == nullptr)
        {
            if (targetSum == 0)
            {
                path_list.push_back(path);
            }
            
            return;
        }

        // Recursion and Backtracking.
        if (current->left != nullptr)
        {
            path.push_back(current->left->val);
            find_path(current->left, targetSum - current->left->val);
            path.pop_back();
        }
        if (current->right != nullptr)
        {
            path.push_back(current->right->val);
            find_path(current->right, targetSum - current->right->val);
            path.pop_back();
        }
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution solution;
    vector<vector<int>> path_list = solution.pathSum(root, 22);

    for (size_t i = 0; i < path_list.size(); i++)
    {
        for (size_t j = 0; j < path_list[i].size(); j++)
        {
            cout << path_list[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}

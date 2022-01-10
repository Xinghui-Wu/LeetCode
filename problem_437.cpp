/**
 * 437. Path Sum III
 * 
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [0, 1000].
 *   -10^9 <= Node.val <= 10^9
 *   -1000 <= targetSum <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
private:
    int num_paths;

public:
    int pathSum(TreeNode* root, int targetSum)
    {
        num_paths = 0;

        traverse(root, targetSum);

        return num_paths;
    }


    /**
     * Traverse the binary tree with DFS recursively.
     * Visit each and every node in the tree.
     */
    void traverse(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }

        find_path(root, targetSum);

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);
    }


    /**
     * Start from the root node, and find a path that satisfies the requirement.
     */
    void find_path(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }
        
        targetSum -= root->val;
        
        if (targetSum == 0)
        {
            num_paths++;
        }

        find_path(root->left, targetSum);
        find_path(root->right, targetSum);
    }
};


int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int num_paths = solution.pathSum(root, 8);

    cout << num_paths << endl;

    return 0;
}

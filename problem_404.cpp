/**
 * 404. Sum of Left Leaves
 * 
 * Given the root of a binary tree, return the sum of all left leaves.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 1000].
 *   -1000 <= Node.val <= 1000
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        return dfs(root);
    }


    int dfs(TreeNode* root)
    {
        int sum = 0;

        if (root->left != nullptr)
        {
            sum += dfs(root->left);

            if (root->left->left == nullptr && root->left->right == nullptr)
            {
                sum += root->left->val;
            }
        }
        if (root->right != nullptr)
        {
            sum += dfs(root->right);
        }
        
        return sum;
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
    int sum = solution.sumOfLeftLeaves(root);

    cout << sum << endl;
    
    return 0;
}

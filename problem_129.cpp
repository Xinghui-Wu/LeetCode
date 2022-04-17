/**
 * 129. Sum Root to Leaf Numbers
 * 
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 * Each root-to-leaf path in the tree represents a number.
 *   For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * Return the total sum of all root-to-leaf numbers.
 * Test cases are generated so that the answer will fit in a 32-bit integer.
 * A leaf node is a node with no children.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 1000].
 *   0 <= Node.val <= 9
 *   The depth of the tree will not exceed 10.
 * 
 * Difficulty: Medium
 * Related Topics: Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include "node.h"

using namespace std;


class Solution
{
public:
    int sumNumbers(TreeNode* root)
    {
        int sum = 0;

        dfs(root, sum, 0);

        return sum;
    }


    void dfs(TreeNode* current, int& sum, int current_sum)
    {
        current_sum = 10 * current_sum + current->val;

        if (current->left == nullptr && current->right == nullptr)
        {
            sum += current_sum;
        }
        else
        {
            if (current->left != nullptr)
            {
                dfs(current->left, sum, current_sum);
            }
            if (current->right != nullptr)
            {
                dfs(current->right, sum, current_sum);
            }
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    Solution solution;
    int sum = solution.sumNumbers(root);

    cout << sum << endl;

    return 0;
}

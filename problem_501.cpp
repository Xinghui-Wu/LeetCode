/**
 * 501. Find Mode in Binary Search Tree
 * 
 * Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
 * If the tree has more than one mode, return them in any order.
 * Assume a BST is defined as follows:
 *   The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 *   The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 *   Both the left and right subtrees must also be binary search trees.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 10^4].
 *   -10^5 <= Node.val <= 10^5
 * 
 * Follow up:
 *   Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
 */
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;


class Solution
{
public:
    vector<int> findMode(TreeNode* root)
    {
        vector<int> modes;

        TreeNode* previous = nullptr;

        int max_count = 0;
        int count = 0;

        dfs(root, previous, modes, max_count, count);

        return modes;
    }


    void dfs(TreeNode* current, TreeNode*& previous, vector<int>& modes, int& max_count, int& count)
    {
        if (current != nullptr)
        {
            dfs(current->left, previous, modes, max_count, count);

            if (previous == nullptr || current->val != previous->val)
            {
                count = 1;
            }
            else
            {
                count++;
            }

            if (count == max_count)
            {
                modes.push_back(current->val);
            }
            else if (count > max_count)
            {
                max_count = count;
                modes.clear();
                modes.push_back(current->val);
            }

            previous = current;

            dfs(current->right, previous, modes, max_count, count);
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution solution;
    vector<int> modes = solution.findMode(root);

    for (size_t i = 0; i < modes.size(); i++)
    {
        cout << modes[i] << endl;
    }
    
    return 0;
}

/**
 * 257. Binary Tree Paths
 * 
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * A leaf is a node with no children.
 * 
 * Constraints:
 *   The number of nodes in the tree is in the range [1, 100].
 *   -100 <= Node.val <= 100
 * 
 * Difficulty: Easy
 * Related Topics: String, Backtracking, Tree, Depth-First Search, Binary Tree
 */
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;


class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> paths;
        vector<int> path;

        dfs(root, paths, path);

        return paths;
    }


    void dfs(TreeNode* root, vector<string>& paths, vector<int>& path)
    {
        if (root == nullptr)
        {
            return;
        }

        path.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr)
        {
            string current_path = to_string(path[0]);

            for (size_t i = 1; i < path.size(); i++)
            {
                current_path.append("->");
                current_path.append(to_string(path[i]));
            }
            
            paths.push_back(current_path);
        }
        else
        {
            dfs(root->left, paths, path);
            dfs(root->right, paths, path);
        }
        
        path.pop_back();
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);

    for (size_t i = 0; i < paths.size(); i++)
    {
        cout << paths[i] << endl;
    }
    
    return 0;
}

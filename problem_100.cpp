/**
 * 100. Same Tree
 * 
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * 
 * Constraints:
 *   The number of nodes in both trees is in the range [0, 100].
 *   -10^4 <= Node.val <= 10^4
 * 
 * Difficulty: Easy
 * Related Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */
#include <iostream>
#include <queue>
#include "node.h"

using namespace std;


class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // Handle the exceptional cases.
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if ((p == nullptr) != (q == nullptr))
        {
            return false;
        }
        
        queue<TreeNode*> p_tree_node_queue;
        p_tree_node_queue.push(p);

        queue<TreeNode*> q_tree_node_queue;
        q_tree_node_queue.push(q);

        TreeNode* p_current;
        TreeNode* q_current;

        // Breadth-First Search with Queue
        while (!p_tree_node_queue.empty() && !q_tree_node_queue.empty())
        {
            p_current = p_tree_node_queue.front();
            p_tree_node_queue.pop();
            
            q_current = q_tree_node_queue.front();
            q_tree_node_queue.pop();

            // Check whether the values of the two nodes are the same.
            if (p_current->val != q_current->val)
            {
                return false;
            }

            // Check the left childs of the two nodes.
            if ((p_current->left == nullptr) != (q_current->left == nullptr))
            {
                return false;
            }
            if (p_current->left != nullptr && q_current->left != nullptr)
            {
                p_tree_node_queue.push(p_current->left);
                q_tree_node_queue.push(q_current->left);
            }

            // Check the right childs of the two nodes.
            if ((p_current->right == nullptr) != (q_current->right == nullptr))
            {
                return false;
            }
            if (p_current->right != nullptr && q_current->right != nullptr)
            {
                p_tree_node_queue.push(p_current->right);
                q_tree_node_queue.push(q_current->right);
            }
        }
        
        return true;
    }
};


int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    bool is_same = solution.isSameTree(p, q);

    cout << is_same << endl;

    return 0;
}

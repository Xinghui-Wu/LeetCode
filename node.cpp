#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

using namespace std;


/**
 * Create a link list and return its head node.
 */
ListNode* create_list(int val_list[], int length)
{
    ListNode* head = new ListNode(val_list[0]);
    ListNode* current = head;

    for (size_t i = 1; i < length; i++)
    {
        current->next = new ListNode(val_list[i]);
        current = current->next;
    }

    return head;
}


/**
 * Output the values of the given link list.
 */
void output_list(ListNode* list)
{
    while (list != nullptr)
    {
        std::cout << list->val << std::endl;
        list = list->next;
    }
}


/**
 * Output the binary tree level order traversal.
 */
void output_level_order_traversal(TreeNode* root)
{
    vector<vector<int>> level_order_val_list;

    if (root == nullptr)
    {
        return;
    }
        
    queue<TreeNode*> tree_node_queue;
    tree_node_queue.push(root);

    TreeNode* current;
    int num_level_tree_nodes;

    // Breadth-First Search with Queue
    while (!tree_node_queue.empty())
    {
        num_level_tree_nodes = tree_node_queue.size();

        // Expand the current vector when going down to the next level.
        vector<int> level_val_list(num_level_tree_nodes);

        // All tree nodes in the current queue are from the same level.
        for (size_t i = 0; i < num_level_tree_nodes; i++)
        {
            current = tree_node_queue.front();
            tree_node_queue.pop();

            level_val_list[i] = current->val;

            if (current->left != nullptr)
            {
                tree_node_queue.push(current->left);
            }
            if (current->right != nullptr)
            {
                tree_node_queue.push(current->right);
            }
        }

        level_order_val_list.push_back(level_val_list);
    }

    for (size_t i = 0; i < level_order_val_list.size(); i++)
    {
        for (size_t j = 0; j < level_order_val_list[i].size(); j++)
        {
            cout << level_order_val_list[i][j] << '\t';
        }
        cout << endl;
    }
}

/**
 * 96. Unique Binary Search Trees
 * 
 * Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * Constraints:
 *   1 <= n <= 19
 * 
 * Difficulty: Medium
 * Related Topics: Math, Dynamic Programming, Tree, Binary Search Tree, Binary Tree
 */
#include <iostream>

using namespace std;


class Solution {
private:
    static int num_trees_record[20];
    static int num_records;

public:
    int numTrees(int n)
    {
        // If the result has already been saved, return it directly.
        if (n <= num_records)
        {
            return num_trees_record[n];
        }

        // The number of nodes in the left and right subtrees respectively.
        int left;
        int right;

        // Start from the next record to be saved.
        for (int i = num_records + 1; i <= n; i++)
        {
            // Select the node to be the tree root.
            for (int j = 1; j <= i; j++)
            {
                left = j - 1;
                right = i - j;

                // Use the results of subproblems of left and right subtrees.
                num_trees_record[i] += num_trees_record[left] * num_trees_record[right];
            }
        }

        num_records = n;
        
        return num_trees_record[n];
    }
};

// Initialize the static variables.
int Solution::num_trees_record[] = {1, 1, 2, 5};
int Solution::num_records = 3;


int main()
{
    Solution solution;

    for (int n = 1; n <= 19; n++)
    {
        cout << solution.numTrees(n) << endl;;
    }
    
    return 0;
}

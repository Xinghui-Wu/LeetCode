/**
 * 77. Combinations
 * 
 * Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
 * You may return the answer in any order.
 * 
 * Constraints:
 *   1 <= n <= 20
 *   1 <= k <= n
 * 
 * Difficulty: Medium
 * Related Topics: Array, Backtracking
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> combinations;
        vector<int> path;

        backtracking(combinations, path, n, k, 1);

        return combinations;
    }


    void backtracking(vector<vector<int>>& combinations, vector<int>& path, int n, int k, int start)
    {
        // There are already k elements along the current path.
        if (path.size() == k)
        {
            combinations.push_back(path);

            return;
        }
        
        for (int i = start; i <= n - (k - path.size()) + 1; i++)
        {
            // Process the current node.
            path.push_back(i);
            // Recursively search for the next element along the path.
            backtracking(combinations, path, n, k, i + 1);
            // Withdraw this step.
            path.pop_back();
        }
    }
};


int main()
{
    int n = 4;
    int k = 2;

    Solution solution;
    vector<vector<int>> combinations = solution.combine(n, k);

    for (size_t i = 0; i < combinations.size(); i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            cout << combinations[i][j] << "\t";
        }
        
        cout << endl;
    }
    
    return 0;
}

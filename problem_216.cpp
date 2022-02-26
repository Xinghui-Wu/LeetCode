/**
 * 216. Combination Sum III
 * 
 * Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 *   Only numbers 1 through 9 are used.
 *   Each number is used at most once.
 * Return a list of all possible valid combinations.
 * The list must not contain the same combination twice, and the combinations may be returned in any order.
 * 
 * Constraints:
 *   2 <= k <= 9
 *   1 <= n <= 60
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
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> combinations;
        vector<int> path;

        backtracking(combinations, path, k, n, 1, 0);

        return combinations;
    }


    void backtracking(vector<vector<int>>& combinations, vector<int>& path, int k, int n, int start, int sum)
    {
        // There are already k elements along the current path.
        if (path.size() == k)
        {
            if (sum == n)
            {
                combinations.push_back(path);
            }

            return;
        }
        
        for (int i = start; i <= 10 - k + path.size() && sum + i <= n; i++)
        {
            // Process the current node.
            path.push_back(i);
            // Recursively search for the next element along the path.
            backtracking(combinations, path, k, n, i + 1, sum + i);
            // Withdraw this step.
            path.pop_back();
        }
    }
};


int main()
{
    int k = 3;
    int n = 9;

    Solution solution;
    vector<vector<int>> combinations = solution.combinationSum3(k, n);

    for (size_t i = 0; i < combinations.size(); i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            cout << combinations[i][j] << "\t";
        }
        
        cout << endl;
    }
    
    return 0;
}

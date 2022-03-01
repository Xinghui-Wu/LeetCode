/**
 * 40. Combination Sum II
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 *   The solution set must not contain duplicate combinations.
 * 
 * Constraints:
 *   1 <= candidates.length <= 100
 *   1 <= candidates[i] <= 50
 *   1 <= target <= 30
 * 
 * Difficulty: Medium
 * Related Topics: Array, Backtracking
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> combinations;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        backtracking(candidates, combinations, path, target, 0, 0);

        return combinations;
    }


    void backtracking(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& path, int target, int sum, int index)
    {
        if (sum == target)
        {
            combinations.push_back(path);

            return;
        }
        
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            
            // Process the current node.
            path.push_back(candidates[i]);
            // Recursively search for the next element along the path.
            backtracking(candidates, combinations, path, target, sum + candidates[i], i + 1);
            // Withdraw this step.
            path.pop_back();
        }
    }
};


int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution solution;
    vector<vector<int>> combinations = solution.combinationSum2(candidates, target);

    for (size_t i = 0; i < combinations.size(); i++)
    {
        for (size_t j = 0; j < combinations[i].size(); j++)
        {
            cout << combinations[i][j] << "\t";
        }
        
        cout << endl;
    }
    
    return 0;
}

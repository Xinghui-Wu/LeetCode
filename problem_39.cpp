/**
 * 39. Combination Sum
 * 
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
 * You may return the combinations in any order.
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
 * 
 * Constraints:
 *   1 <= candidates.length <= 30
 *   1 <= candidates[i] <= 200
 *   All elements of candidates are distinct.
 *   1 <= target <= 500
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> combinations;
        vector<int> path;

        backtracking(candidates, combinations, path, target, 0, 0);

        return combinations;
    }


    void backtracking(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& path, int target, int sum, int index)
    {
        if (sum > target)
        {
            return;
        }
        
        if (sum == target)
        {
            combinations.push_back(path);

            return;
        }
        
        for (int i = index; i < candidates.size(); i++)
        {
            // Process the current node.
            path.push_back(candidates[i]);
            // Recursively search for the next element along the path.
            backtracking(candidates, combinations, path, target, sum + candidates[i], i);
            // Withdraw this step.
            path.pop_back();
        }
    }
};


int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution solution;
    vector<vector<int>> combinations = solution.combinationSum(candidates, target);

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

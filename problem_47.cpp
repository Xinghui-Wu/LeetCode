/**
 * 47. Permutations II
 * 
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 * 
 * Constraints:
 *   1 <= nums.length <= 8
 *   -10 <= nums[i] <= 10
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
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> permutations;
        vector<int> path;
        vector<bool> is_used(nums.size());

        sort(nums.begin(), nums.end());

        backtracking(nums, permutations, path, is_used);

        return permutations;
    }


    void backtracking(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& path, vector<bool>& is_used)
    {
        if (path.size() == nums.size())
        {
            permutations.push_back(path);

            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !is_used[i - 1])
            {
                continue;
            }
            
            if (!is_used[i])
            {
                path.push_back(nums[i]);
                is_used[i] = true;
                backtracking(nums, permutations, path, is_used);
                is_used[i] = false;
                path.pop_back();
            }
        }
    }
};


int main()
{
    vector<int> nums = {1, 1, 2};

    Solution solution;
    vector<vector<int>> permutations = solution.permuteUnique(nums);

    for (size_t i = 0; i < permutations.size(); i++)
    {
        for (size_t j = 0; j < nums.size(); j++)
        {
            cout << permutations[i][j] << '\t';
        }
        
        cout << endl;
    }
    
    return 0;
}

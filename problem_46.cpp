/**
 * 46. Permutations
 * 
 * Given an array nums of distinct integers, return all the possible permutations.
 * You can return the answer in any order.
 * 
 * Constraints:
 *   1 <= nums.length <= 6
 *   -10 <= nums[i] <= 10
 *   All the integers of nums are unique.
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
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> permutations;
        vector<int> path;
        vector<bool> is_used(21);

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
            if (!is_used[nums[i] + 10])
            {
                path.push_back(nums[i]);
                is_used[nums[i] + 10] = true;
                backtracking(nums, permutations, path, is_used);
                is_used[nums[i] + 10] = false;
                path.pop_back();
            }
        }
    }
};


int main()
{
    vector<int> nums = {1, 2, 3};

    Solution solution;
    vector<vector<int>> permutations = solution.permute(nums);

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

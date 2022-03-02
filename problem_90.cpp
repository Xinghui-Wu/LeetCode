/**
 * 90. Subsets II
 * 
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets.
 * Return the solution in any order.
 * 
 * Constraints:
 *   1 <= nums.length <= 10
 *   -10 <= nums[i] <= 10
 * 
 * Difficulty: Medium
 * Related Topics: Array, Backtracking, Bit Manipulation
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> nums_subsets(1);
        vector<int> path;

        sort(nums.begin(), nums.end());

        backtracking(nums, nums_subsets, path, 0);

        return nums_subsets;
    }


    void backtracking(vector<int>& nums, vector<vector<int>>& nums_subsets, vector<int> path, int index)
    {
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            path.push_back(nums[i]);
            nums_subsets.push_back(path);
            backtracking(nums, nums_subsets, path, i + 1);
            path.pop_back();
        }
    }
};


int main()
{
    vector<int> nums = {1, 2, 2};

    Solution solution;
    vector<vector<int>> nums_subsets = solution.subsetsWithDup(nums);

    for (size_t i = 0; i < nums_subsets.size(); i++)
    {
        for (size_t j = 0; j < nums_subsets[i].size(); j++)
        {
            cout << nums_subsets[i][j] << '\t';
        }
        
        cout << endl;
    }
    
    return 0;
}

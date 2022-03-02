/**
 * 78. Subsets
 * 
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets.
 * Return the solution in any order.
 * 
 * Constraints:
 *   1 <= nums.length <= 10
 *   -10 <= nums[i] <= 10
 *   All the numbers of nums are unique.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Backtracking, Bit Manipulation
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> nums_subsets(1);
        vector<int> path;

        backtracking(nums, nums_subsets, path, 0);

        return nums_subsets;
    }


    void backtracking(vector<int>& nums, vector<vector<int>>& nums_subsets, vector<int> path, int index)
    {
        if (index >= nums.size())
        {
            return;
        }
        
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            nums_subsets.push_back(path);
            backtracking(nums, nums_subsets, path, i + 1);
            path.pop_back();
        }
    }
};


int main()
{
    vector<int> nums = {1, 2, 3};

    Solution solution;
    vector<vector<int>> nums_subsets = solution.subsets(nums);

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

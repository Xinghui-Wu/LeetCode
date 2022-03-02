/**
 * 491. Increasing Subsequences
 * 
 * Given an integer array nums, return all the different possible increasing subsequences of the given array with at least two elements.
 * You may return the answer in any order.
 * The given array may contain duplicates, and two equal integers should also be considered a special case of increasing sequence.
 * 
 * Constraints:
 *   1 <= nums.length <= 15
 *   -100 <= nums[i] <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Array, Hash Table, Backtracking, Bit Manipulation
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<vector<int>> subsequences;

        if (nums.size() < 2)
        {
            return subsequences;
        }
        
        vector<int> path;

        backtracking(nums, subsequences, path, 0);

        return subsequences;
    }


    void backtracking(vector<int>& nums, vector<vector<int>>& subsequences, vector<int> path, int index)
    {
        if (path.size() >= 2)
        {
            subsequences.push_back(path);
        }

        bool is_used[201] = {false};

        for (int i = index; i < nums.size(); i++)
        {
            if (is_used[nums[i] + 100] || (!path.empty() && path.back() > nums[i]))
            {
                continue;
            }

            is_used[nums[i] + 100] = true;
                
            path.push_back(nums[i]);
            backtracking(nums, subsequences, path, i + 1);
            path.pop_back();
        }
    }
};


int main()
{
    vector<int> nums = {4, 4, 3, 2, 1};

    Solution solution;
    vector<vector<int>> subsequences = solution.findSubsequences(nums);

    for (size_t i = 0; i < subsequences.size(); i++)
    {
        for (size_t j = 0; j < subsequences[i].size(); j++)
        {
            cout << subsequences[i][j] << '\t';
        }
        
        cout << endl;
    }
    
    return 0;
}

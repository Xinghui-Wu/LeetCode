/**
 * 377. Combination Sum IV
 * 
 * Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
 * The test cases are generated so that the answer can fit in a 32-bit integer.
 * 
 * Constraints:
 *   1 <= nums.length <= 200
 *   1 <= nums[i] <= 1000
 *   All the elements of nums are unique.
 *   1 <= target <= 1000
 * 
 * Follow up:
 *   What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (j >= nums[i] && dp[j - nums[i]] < INT32_MAX - dp[j])
                {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        
        return dp[target];
    }
};


int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;

    Solution solution;
    int num_combinations = solution.combinationSum4(nums, target);

    cout << num_combinations << endl;

    return 0;
}

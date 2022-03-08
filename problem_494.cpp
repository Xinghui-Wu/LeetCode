/**
 * 494. Target Sum
 * 
 * You are given an integer array nums and an integer target.
 * You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
 * Return the number of different expressions that you can build, which evaluates to target.
 * 
 * Constraints:
 *   1 <= nums.length <= 20
 *   0 <= nums[i] <= 1000
 *   0 <= sum(nums[i]) <= 1000
 *   -1000 <= target <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Backtracking
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // sum1 + sum2 = sum, sum1 - sum2 = target
        if ((sum + target) % 2 == 1)
        {
            return 0;
        }

        if (abs(target) > sum)
        {
            return 0;
        }
        
        int sum1 = (sum + target) / 2;

        // dp[j] represents the number of ways fo fill up a bag with capacity of j.
        vector<int> dp(sum1 + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum1; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        
        return dp[sum1];
    }
};


int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution solution;
    int num_ways = solution.findTargetSumWays(nums, target);

    cout << num_ways << endl;

    return 0;
}

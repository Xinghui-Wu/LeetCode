/**
 * 55. Jump Game
 * 
 * You are given an integer array nums.
 * You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   0 <= nums[i] <= 10^5
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Greedy
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return true;
        }
        
        // dp[i] shows whether it is feasible to jump to i.
        bool dp[n];

        for (int i = 0; i < n; i++)
        {
            dp[i] = false;
        }
        
        dp[0] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && j + nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n - 1];
    }
};


int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution solution;
    bool is_feasible = solution.canJump(nums);

    cout << is_feasible << endl;

    return 0;
}

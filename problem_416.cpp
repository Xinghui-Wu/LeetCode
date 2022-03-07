/**
 * 416. Partition Equal Subset Sum
 * 
 * Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 * 
 * Constraints:
 *   1 <= nums.length <= 200
 *   1 <= nums[i] <= 100
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
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if (sum % 2 == 1)
        {
            return false;
        }
        
        sum /= 2;

        vector<int> dp(sum + 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        
        if (dp[sum] == sum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    vector<int> nums = {1, 5, 11, 5};

    Solution solution;
    bool is_partition = solution.canPartition(nums);

    cout << is_partition << endl;

    return 0;
}

/**
 * 300. Longest Increasing Subsequence
 * 
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 * A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
 * For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 * Constraints:
 *   1 <= nums.length <= 2500
 *   -10^4 <= nums[i] <= 10^4
 * 
 * Follow up:
 *   Can you come up with an algorithm that runs in O(n log(n)) time complexity?
 * 
 * Difficulty: Medium
 * Related Topics: Array, Binary Search, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int length = 1;

        // dp[i] is the length of the LIS ending at i.
        int dp[nums.size()];

        for (size_t i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
        }

        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            length = max(length, dp[i]);
        }
        
        return length;
    }
};


int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution solution;
    int length = solution.lengthOfLIS(nums);

    cout << length << endl;

    return length;
}

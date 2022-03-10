/**
 * 674. Longest Continuous Increasing Subsequence
 * 
 * Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray).
 * The subsequence must be strictly increasing.
 * A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
 * 
 * Constraints:
 *   1 <= nums.length <= 104
 *   -10^9 <= nums[i] <= 10^9
 * 
 * Difficulty: Easy
 * Related Topics: Array
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int length = 1;
        int dp = 1;

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp += 1;
                length = max(length, dp);
            }
            else
            {
                dp = 1;
            }
        }
        
        return length;
    }
};


int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};

    Solution solution;
    int length = solution.findLengthOfLCIS(nums);

    cout << length << endl;

    return length;
}

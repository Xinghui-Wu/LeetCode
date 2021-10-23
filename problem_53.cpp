/**
 * 53. Maximum Subarray
 * 
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * A subarray is a contiguous part of an array.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   -10^4 <= nums[i] <= 10^4
 * 
 * Follow up:
 *   If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Divide and Conquer, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        // The maximum sum of the first i elements.
        int subarray_sum = nums[0];
        // The maximum sum of the subvector that ends at index i.
        int current_sum = nums[0];

        // The format of the sub problems should be maxSubArray(nums, i), which means the maximum subarray of nums[0: i].
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (current_sum > 0)
            {
                current_sum += nums[i];
            }
            else
            {
                current_sum = nums[i];
            }

            if (current_sum > subarray_sum)
            {
                subarray_sum = current_sum;
            }
        }

        return subarray_sum;
    }
};


int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solution;
    int subarray_sum = solution.maxSubArray(nums);

    cout << subarray_sum << endl;

    return 0;
}

/**
 * 209. Minimum Size Subarray Sum
 * 
 * Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [nums[l], nums[l+1], ..., nums[r-1], nums[r]] of which the sum is greater than or equal to target.
 * If there is no such subarray, return 0 instead.
 * 
 * Constraints:
 *   1 <= target <= 10^9
 *   1 <= nums.length <= 10^5
 *   1 <= nums[i] <= 10^5
 * 
 * Follow up:
 *   If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
 * 
 * Difficulty: Medium
 * Related Topics: Array, Binary Search, Sliding Window, Prefix Sum
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int min_subarray_length = nums.size() + 1;

        int start = 0;
        int end = 0;
        int sum = 0;

        while (end < nums.size())
        {
            sum += nums[end];

            while (sum >= target)
            {
                min_subarray_length = min(min_subarray_length, end - start + 1);
                
                sum -= nums[start];
                start++;
            }
            
            end++;
        }

        if (min_subarray_length <= nums.size())
        {
            return min_subarray_length;
        }
        
        return 0;
    }
};


int main()
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    Solution solution;
    int min_subarray_length = solution.minSubArrayLen(target, nums);

    cout << min_subarray_length << endl;

    return 0;
}

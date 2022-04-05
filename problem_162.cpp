/**
 * 162. Find Peak Element
 * 
 * A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, and return its index.
 * If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * You must write an algorithm that runs in O(log n) time.
 * 
 * Constraints:
 *   1 <= nums.length <= 1000
 *   -2^31 <= nums[i] <= 2^31 - 1
 *   nums[i] != nums[i + 1] for all valid i.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Binary Search
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int length = nums.size();

        if (length == 1)
        {
            return 0;
        }
        
        if (nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[length - 1] > nums[length - 2])
        {
            return length - 1;
        }

        for (int i = 1; i < length - 1; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                return i;
            }
        }
        
        return 0;
    }
};


int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    Solution solution;
    int peak_index = solution.findPeakElement(nums);

    cout << peak_index << endl;

    return 0;
}

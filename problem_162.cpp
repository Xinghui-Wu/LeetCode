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
        nums.insert(nums.begin(), INT32_MIN);
        nums.push_back(INT32_MIN);

        int left = 1;
        int right = nums.size() - 2;
        int mid;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid - 1;
            }

            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
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

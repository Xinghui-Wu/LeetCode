/**
 * 215. Kth Largest Element in an Array
 * 
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Constraints:
 *   1 <= k <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};


int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    Solution solution;
    int kth_largest = solution.findKthLargest(nums, k);

    cout << kth_largest << endl;

    return 0;
}

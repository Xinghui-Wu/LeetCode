/**
 * 4. Median of Two Sorted Arrays
 * 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log(m + n)).
 * 
 * Constraints:
 *   nums1.length == m
 *   nums2.length == n
 *   0 <= m <= 1000
 *   0 <= n <= 1000
 *   1 <= m + n <= 2000
 *   -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * Difficulty: Hard
 * Related Topics: Array, Binary Search, Divide and Conquer
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int length = nums1.size() + nums2.size();
        vector<int> nums(length);

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        
        if (length >> 1 << 1 == length)
        {
            return (double) (nums[(length - 1) / 2] + nums[(length - 1) / 2 + 1]) / 2;
        }
        else
        {
            return (double) nums[length / 2];
        }
    }
};


int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution solution;
    double median = solution.findMedianSortedArrays(nums1, nums2);

    cout << median << endl;

    return 0;
}

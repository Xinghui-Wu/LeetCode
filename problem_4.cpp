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

using namespace std;


class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        // Make sure that the number of elements in the first vector is not larger than that in the second one.
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Divide a set into two subsets equally, while the maximum of the first subset is not larger than the minimum of the second subset.
        // Suppose the first subset has nums1[0] to nums1[i - 1] and nums2[0] to nums2[j - 1] and the second subset has nums1[i] to nums1[m - 1] and nums2[j] to nums2[n - 1].
        // When m + n is even, i + j = m - i + n - j, and when m + n is odd, i + j = m - i + n - j + 1.
        // So we can derive i + j = (m + n + 1) / 2, and use i to represent j that j = (m + n + 1) / 2 - i.
        // We should find i so that nums2[j - 1] <= nums1[i] and nums1[i - 1] <= nums2[j].
        // It is equivalent to find the largest i that nums1[i - 1] <= nums2[j] with binary search.
        int i, j;
        int nums1_i_1, nums1_i, nums2_j_1, nums2_j;

        int left = 0;
        int right = m;

        int left_max;
        int right_min;

        while (left <= right)
        {
            i = (left + right) / 2;
            j = (m + n + 1) / 2 - i;

            nums1_i_1 = (i == 0 ? INT32_MIN : nums1[i - 1]);
            nums1_i = (i == m ? INT32_MAX : nums1[i]);
            nums2_j_1 = (j == 0 ? INT32_MIN : nums2[j - 1]);
            nums2_j = (j == n ? INT32_MAX : nums2[j]);

            if (nums1_i_1 <= nums2_j)
            {
                left_max = max(nums1_i_1, nums2_j_1);
                right_min = min(nums1_i, nums2_j);

                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }
        
        if ((m + n) >> 1 << 1 == (m + n))
        {
            return (double) (left_max + right_min) / 2;
        }
        else
        {
            return (double) left_max;
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

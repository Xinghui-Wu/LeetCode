/**
 * 88. Merge Sorted Array
 * 
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
 * To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * 
 * Constraints:
 *   nums1.length == m + n
 *   nums2.length == n
 *   0 <= m, n <= 200
 *   1 <= m + n <= 200
 *   -10^9 <= nums1[i], nums2[j] <= 10^9
 * 
 * Follow up:
 *   Can you come up with an algorithm that runs in O(m + n) time?
 * 
 * Difficulty: Easy
 * Related Topics: Array, Two Pointers, Sorting
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge the two sorted arrays with two pointers from the end instead of start, avoiding a temp array.
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
        
        // If nums2 still remains some elements, merge them into nums1.
        if (j >= 0)
        {
            for (; k >= 0; k--)
            {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};


int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    for (size_t i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << endl;
    }
    
    return 0;
}

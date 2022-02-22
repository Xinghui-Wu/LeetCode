/**
 * 454. 4Sum II
 * 
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
 *   0 <= i, j, k, l < n
 *   nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 * 
 * Constraints:
 *   n == nums1.length
 *   n == nums2.length
 *   n == nums3.length
 *   n == nums4.length
 *   1 <= n <= 200
 *   -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28
 * 
 * Difficulty: Medium
 * Related Topics: Array, Hash Table
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int nums_tuples = 0;

        unordered_map<int, int> sum_map;

        for (int a: nums1)
        {
            for (int b: nums2)
            {
                sum_map[a + b]++;
            }
        }

        for (int c: nums3)
        {
            for (int d: nums4)
            {
                if (sum_map.count(0 - c - d) > 0)
                {
                    nums_tuples += sum_map[0 - c - d];
                }
            }
        }
        
        return nums_tuples;
    }
};


int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    Solution solution;
    int num_tuples = solution.fourSumCount(nums1, nums2, nums3, nums4);

    cout << num_tuples << endl;

    return 0;
}

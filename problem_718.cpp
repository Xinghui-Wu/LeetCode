/**
 * 718. Maximum Length of Repeated Subarray
 * 
 * Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
 * 
 * Constraints:
 *   1 <= nums1.length, nums2.length <= 1000
 *   0 <= nums1[i], nums2[i] <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Array, Binary Search, Dynamic Programming, Sliding Window, Rolling Hash, Hash Function
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int length = 0;

        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (size_t i = 1; i <= m; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                length = max(length, dp[i][j]);
            }
        }

        return length;
    }
};


int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    Solution solution;
    int length = solution.findLength(nums1, nums2);

    cout << length << endl;

    return 0;
}

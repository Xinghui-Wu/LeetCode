/**
 * 1035. Uncrossed Lines
 * 
 * You are given two integer arrays nums1 and nums2.
 * We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
 * We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
 *   nums1[i] == nums2[j], and
 *   the line we draw does not intersect any other connecting (non-horizontal) line.
 * Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
 * Return the maximum number of connecting lines we can draw in this way.
 * 
 * Constraints:
 *   1 <= nums1.length, nums2.length <= 500
 *   1 <= nums1[i], nums2[j] <= 2000
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        int dp[m + 1][n + 1];

        for (size_t i = 0; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for (size_t j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }

        for (size_t i = 1; i <= m; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};


int main()
{
    vector<int> nums1 = {1, 3, 7, 1, 7, 5};
    vector<int> nums2 = {1, 9, 2, 5, 1};

    Solution solution;
    int num_lines = solution.maxUncrossedLines(nums1, nums2);

    cout << num_lines << endl;

    return 0;
}

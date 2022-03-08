/**
 * 474. Ones and Zeroes
 * 
 * You are given an array of binary strings strs and two integers m and n.
 * Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
 * A set x is a subset of a set y if all elements of x are also elements of y.
 * 
 * Constraints:
 *   1 <= strs.length <= 600
 *   1 <= strs[i].length <= 100
 *   strs[i] consists only of digits '0' and '1'.
 *   1 <= m, n <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Array, String, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int count[2];

        for (size_t i = 0; i < strs.size(); i++)
        {
            count[0] = 0;
            count[1] = 0;

            for (char c: strs[i])
            {
                count[c - '0']++;
            }

            for (int i = m; i >= count[0]; i--)
            {
                for (int j = n; j >= count[1]; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - count[0]][j - count[1]] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};


int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;

    Solution solution;
    int subset_size = solution.findMaxForm(strs, m, n);

    cout << subset_size << endl;

    return 0;
}

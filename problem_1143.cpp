/**
 * 1143. Longest Common Subsequence
 * 
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 * If there is no common subsequence, return 0.
 * A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
 * For example, "ace" is a subsequence of "abcde".
 * A common subsequence of two strings is a subsequence that is common to both strings.
 * 
 * Constraints:
 *   1 <= text1.length, text2.length <= 1000
 *   text1 and text2 consist of only lowercase English characters.
 * 
 * Difficulty: Medium
 * Related Topics: String, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

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
                if (text1[i - 1] == text2[j - 1])
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
    string text1 = "abcde";
    string text2 = "ace";

    Solution solution;
    int length = solution.longestCommonSubsequence(text1, text2);

    cout << length << endl;

    return 0;
}

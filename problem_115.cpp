/**
 * 115. Distinct Subsequences
 * 
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
 * A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions.
 * (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 * 
 * Constraints:
 *  1 <= s.length, t.length <= 1000
 *   s and t consist of English letters.
 * 
 * Difficulty: Hard
 * Related Topics: String, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if (m < n)
        {
            return 0;
        }

        // Avoid the overflow.
        unsigned long long dp[m + 1][n + 1];

        for (size_t j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }
        for (size_t i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        
        for (size_t i = 1; i <= m; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};


int main()
{
    string s = "babgbag";
    string t = "bag";

    Solution solution;
    int num_subsequences = solution.numDistinct(s, t);

    cout << num_subsequences << endl;

    return 0;
}

/**
 * 516. Longest Palindromic Subsequence
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
 * 
 * Constraints:
 *   1 <= s.length <= 1000
 *   s consists only of lowercase English letters.
 * 
 * Difficulty: Medium
 * Related Topics: String, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();

        int dp[n][n];
        dp[0][0] = 1;

        for (int i = 1; i < n; i++)
        {
            dp[i][i - 1] = 0;
            dp[i][i] = 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};


int main()
{
    string s = "bbbab";
    
    Solution solution;
    int longest_length = solution.longestPalindromeSubseq(s);

    cout << longest_length << endl;

    return 0;
}

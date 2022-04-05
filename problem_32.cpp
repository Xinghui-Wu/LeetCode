/**
 * 32. Longest Valid Parentheses
 * 
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 
 * Constraints:
 *   0 <= s.length <= 3 * 10^4
 *   s[i] is '(', or ')'.
 * 
 * Difficulty: Hard
 * Related Topics: String, Dynamic Programming, Stack
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();

        if (n == 0)
        {
            return 0;
        }
        
        int length = 0;

        // dp[i] means the longest valid parentheses ending at i.
        int dp[n];

        for (int i = 0; i < n; i++)
        {
            dp[i] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                }
                else if (i > dp[i - 1] && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }

                length = max(length, dp[i]);
            }
        }
        
        return length;
    }
};


int main()
{
    string s = "()()))))()()(";

    Solution solution;
    int length = solution.longestValidParentheses(s);

    cout << length << endl;

    return 0;
}

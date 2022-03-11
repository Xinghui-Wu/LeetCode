/**
 * 392. Is Subsequence
 * 
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
 * (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 * Constraints:
 *   0 <= s.length <= 100
 *   0 <= t.length <= 10^4
 *   s and t consist only of lowercase English letters.
 * 
 * Follow up:
 *   Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 10^9, and you want to check one by one to see if t has its subsequence.
 *   In this scenario, how would you change your code?
 * 
 * Difficulty: Easy
 * Related Topics: Two Pointers, String, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
        {
            return true;
        }

        if (t.empty())
        {
            return false;
        }
        
        int si = 0;
        int sj = s.size() - 1;
        int ti = 0;
        int tj = t.size() - 1;

        while (ti <= tj)
        {
            while (ti <= tj && t[ti] != s[si])
            {
                ti++;
            }
            while (ti <= tj && t[tj] != s[sj])
            {
                tj--;
            }

            if (ti <= tj && t[ti] == s[si] && t[ti] == s[si])
            {
                if (ti == tj && si != sj)
                {
                    return false;
                }
                
                ti++;
                tj--;
                si++;
                sj--;

                if (si > sj)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        
        return false;
    }
};


int main()
{
    string s = "axc";
    string t = "ahbgdc";

    Solution solution;
    bool is_subsequence = solution.isSubsequence(s, t);

    cout << is_subsequence << endl;

    return 0;
}

/**
 * 5. Longest Palindromic Substring
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Constraints:
 *   1 <= s.length <= 1000
 *   s consist of only digits and English letters.
 * 
 * Difficulty: Medium
 * Related Topics: String, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start;
        int max_length = 0;

        int n = s.size();
        int left;
        int right;

        // Fix the center char(s) and expand to both sides.
        for (int i = 0; i < 2 * n - 1; i++)
        {
            left = i / 2;
            right = i / 2 + i % 2;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }

            if (right - left - 1 > max_length)
            {
                start = left + 1;
                max_length = right - left - 1;
            }
        }

        return s.substr(start, max_length);
    }
};


int main()
{
    string s = "babad";

    Solution solution;
    string longest_palindrome = solution.longestPalindrome(s);

    cout << longest_palindrome << endl;

    return 0;
}

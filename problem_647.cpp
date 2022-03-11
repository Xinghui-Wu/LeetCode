/**
 * 647. Palindromic Substrings
 * 
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 * 
 * Constraints:
 *   1 <= s.length <= 1000
 *   s consists of lowercase English letters.
 * 
 * Difficulty: Medium
 * Related Topics: String, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int countSubstrings(string s)
    {
        int num_substrings = 0;
        
        int n = s.size();
        int left;
        int right;

        for (size_t i = 0; i < 2 * n - 1; i++)
        {
            left = i / 2;
            right = i / 2 + i % 2;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
                num_substrings++;
            }
        }

        return num_substrings;
    }
};


int main()
{
    string s = "abc";

    Solution solution;
    int num_substrings = solution.countSubstrings(s);

    cout << num_substrings << endl;

    return 0;
}

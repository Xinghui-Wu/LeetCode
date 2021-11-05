/**
 * 125. Valid Palindrome
 * 
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
 * Alphanumeric characters include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * Constraints:
 *   1 <= s.length <= 2 * 10^5
 *   s consists only of printable ASCII characters.
 * 
 * Difficulty: Easy
 * Related Topics: Two Pointers, String
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Traverse the input string with two pointers.
        int i = 0;
        int j = s.size() - 1;

        while (i <= j)
        {
            // Move the two pointers to the next alphanumeric characters respectively.
            while (i < s.size() && !is_alphanumeric(s[i]))
            {
                i++;
            }
            while (j >= 0 && !is_alphanumeric(s[j]))
            {
                j--;
            }

            // Judge whether the two alphanumeric characters are the same, ignoring cases.
            if (i <= j)
            {
                if (s[i] == s[j] || (s[i] >= 'A' && s[j] >= 'A' && abs(s[i] - s[j]) == 32))
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return true;
    }


    bool is_alphanumeric(char c)
    {
        if (c >= '0' && c <= '9')
        {
            return true;
        }
        if (c >= 'A' && c <= 'Z')
        {
            return true;
        }
        if (c >= 'a' && c <= 'z')
        {
            return true;
        }
        
        return false;
    }
};


int main()
{
    string s = "A man, a plan, a canal: Panama";

    Solution solution;
    bool is_palindrome = solution.isPalindrome(s);

    cout << is_palindrome << endl;

    return 0;
}

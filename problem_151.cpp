/**
 * 151. Reverse Words in a String
 * 
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters.
 * The words in s will be separated by at least one space.
 * Return a string of the words in reverse order concatenated by a single space.
 * Note that s may contain leading or trailing spaces or multiple spaces between two words.
 * The returned string should only have a single space separating the words.
 * Do not include any extra spaces.
 * 
 * Constraints:
 *   1 <= s.length <= 10^4
 *   s contains English letters (upper-case and lower-case), digits, and spaces ' '.
 *   There is at least one word in s.
 * 
 * Follow-up:
 *   If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
 * 
 * Difficulty: Medium
 * Related Topics: Two Pointers, String
 */
#include <iostream>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int i;
        int j;
        int index = 0;

        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (index != 0)
                {
                    s[index++] = ' ';
                }
                
                for (j = i; j < s.size() && s[j] != ' '; j++)
                {
                    s[index++] = s[j];
                }
                
                reverse(s.begin() + index - (j - i), s.begin() + index);

                i = j;
            }
        }
        
        s.erase(s.begin() + index, s.end());

        return s;
    }
};


int main()
{
    string s = "  hello world  ";

    Solution solution;
    s = solution.reverseWords(s);

    cout << s << endl;

    return 0;
}

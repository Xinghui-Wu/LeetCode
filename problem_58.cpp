/**
 * 58. Length of Last Word
 * 
 * Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only.
 * 
 * Constraints:
 *   1 <= s.length <= 10^4
 *   s consists of only English letters and spaces ' '.
 *   There will be at least one word in s.
 * 
 * Difficulty: Easy
 * Related Topics: String
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                length++;
            }
            else if (length > 0)
            {
                return length;
            }
        }
        
        return length;
    }
};


int main()
{
    string s = "a";

    Solution solution;
    int length = solution.lengthOfLastWord(s);

    cout << length << endl;

    return 0;
}

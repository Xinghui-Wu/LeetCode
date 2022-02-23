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

using namespace std;


class Solution
{
public:
    string reverseWords(string s)
    {
        string reversed_words = "";

        int left;
        int right = s.size() - 1;

        while (true)
        {
            while (right >= 0 && s[right] == ' ')
            {
                right--;
            }

            if (right < 0)
            {
                break;
            }

            left = right - 1;
            
            while (left >=0 && s[left] != ' ')
            {
                left--;
            }
            
            reversed_words.push_back(' ');
            reversed_words.append(s.substr(left + 1, right - left));

            right = left;
        }

        return reversed_words.substr(1);
    }
};


int main()
{
    string s = "the sky is blue";

    Solution solution;
    s = solution.reverseWords(s);

    cout << s << endl;

    return 0;
}

/**
 * 459. Repeated Substring Pattern
 * 
 * Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
 * 
 * Constraints:
 *   1 <= s.length <= 10^4
 *   s consists of lowercase English letters.
 * 
 * Difficulty: Easy
 * Related Topics: String, String Matching
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        bool is_repeated;
        int count;
        string sub_str;

        for (int length = s.size() / 2; length >= 1; length--)
        {
            count = s.size() / length;

            if (length * count == s.size())
            {
                is_repeated = true;
                sub_str = s.substr(0, length);

                for (int i = 1; i < count; i++)
                {
                    if (s.substr(i * length, length) != sub_str)
                    {
                        is_repeated = false;
                        break;
                    }
                }
                
                if (is_repeated)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};


int main()
{
    string s = "ababab";

    Solution solution;
    bool is_repeated = solution.repeatedSubstringPattern(s);

    cout << is_repeated << endl;

    return 0;
}

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
        return (s + s).find(s, 1) != s.size();
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

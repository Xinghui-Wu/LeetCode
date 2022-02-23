/**
 * 541. Reverse String II
 * 
 * Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
 * If there are fewer than k characters left, reverse all of them.
 * If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
 * 
 * Constraints:
 *   1 <= s.length <= 10^4
 *   s consists of only lowercase English letters.
 *   1 <= k <= 10^4
 * 
 * Difficulty: Easy
 * Related Topics: Two Pointers, String
 */
#include <iostream>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int length = s.size();

        for (int i = 0; i < length; i += 2 * k)
        {
            if (length - i < k)
            {
                reverse(s.begin() + i, s.end());
            }
            else
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }

        return s;
    }
};


int main()
{
    string s = "abcdefg";
    int k = 2;

    Solution solution;
    string reversed_str = solution.reverseStr(s, k);

    cout << reversed_str << endl;

    return 0;
}

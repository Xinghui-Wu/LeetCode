/**
 * 1047. Remove All Adjacent Duplicates In String
 * 
 * You are given a string s consisting of lowercase English letters.
 * A duplicate removal consists of choosing two adjacent and equal letters and removing them.
 * We repeatedly make duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made.
 * It can be proven that the answer is unique.
 * 
 * Constraints:
 *   1 <= s.length <= 10^5
 *   s consists of lowercase English letters.
 * 
 * Difficulty: Easy
 * Related Topics: String, Stack
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    string removeDuplicates(string s)
    {
        string reduced_str;

        for (char c: s)
        {
            if (!reduced_str.empty() && c == reduced_str.back())
            {
                reduced_str.pop_back();
            }
            else
            {
                reduced_str.push_back(c);
            }
        }
        
        return reduced_str;
    }
};


int main()
{
    string s = "abbaca";

    Solution solution;
    string reduced_str = solution.removeDuplicates(s);

    cout << reduced_str << endl;

    return 0;
}

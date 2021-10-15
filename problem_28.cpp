/**
 * 28. Implement strStr()
 * 
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Clarification:
 *   What should we return when needle is an empty string? This is a great question to ask during an interview.
 *   For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * Constraints:
 *   0 <= haystack.length, needle.length <= 5 * 10^4
 *   haystack and needle consist of only lower-case English characters.
 * 
 * Difficulty: Easy
 * Related Topics: Two Pointers, String, String Matching
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};


int main()
{
    string haystack = "hello";
    string needle = "ll";
    
    Solution solution;
    int index = solution.strStr(haystack, needle);

    cout << index << endl;
    
    return 0;
}

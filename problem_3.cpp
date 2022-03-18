/**
 * 3. Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Constraints:
 *   0 <= s.length <= 5 * 10^4
 *   s consists of English letters, digits, symbols and spaces.
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, String, Sliding Window
 */
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;

        unordered_set<char> char_set;

        // Use i and j to control the sliding window.
        int i = 0;
        int j = 0;

        for (; i < s.size(); i++)
        {
            if (i > 0)
            {
                char_set.erase(s[i - 1]);
            }
            
            while (j < s.size() && char_set.count(s[j]) == 0)
            {
                char_set.insert(s[j]);
                j++;
            }
            
            length = max(length, j - i);
        }

        return length;
    }
};


int main()
{
    string s = "abcabcbb";

    Solution solution;
    int length = solution.lengthOfLongestSubstring(s);

    cout << length << endl;

    return 0;
}

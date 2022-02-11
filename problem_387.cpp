/**
 * 387. First Unique Character in a String
 * 
 * Given a string s, find the first non-repeating character in it and return its index.
 * If it does not exist, return -1.
 * 
 * Constraints:
 *   1 <= s.length <= 10^5
 *   s consists of only lowercase English letters.
 * 
 * Difficulty: Easy
 * Related Topics: Hash Table, String, Queue, Counting
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int firstUniqChar(string s)
    {
        int char_count[26] = {0};

        for (char c: s)
        {
            char_count[c - 'a']++;
        }
        
        for (size_t i = 0; i < s.size(); i++)
        {
            if (char_count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};


int main()
{
    string s = "dddccdbba";

    Solution solution;
    int first_uniq_char_index = solution.firstUniqChar(s);

    cout << first_uniq_char_index << endl;

    return 0;
}

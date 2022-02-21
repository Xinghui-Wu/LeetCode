/**
 * 242. Valid Anagram
 * 
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * 
 * Constraints:
 *   1 <= s.length, t.length <= 5 * 10^4
 *   s and t consist of lowercase English letters.
 * 
 * Follow up:
 *   What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 * 
 * Difficulty: Easy
 * Related Topics: Hash Table, String, Sorting
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        
        int s_count[26] = {0};
        int t_count[26] = {0};

        for (size_t i = 0; i < s.size(); i++)
        {
            s_count[s[i] - 'a']++;
            t_count[t[i] - 'a']++;
        }
        
        for (size_t i = 0; i < 26; i++)
        {
            if (s_count[i] != t_count[i])
            {
                return false;
            }
        }
        
        return true;
    }
};


int main()
{
    string s = "anagram";
    string t = "nagaram";

    Solution solution;
    bool is_anagram = solution.isAnagram(s, t);

    cout << is_anagram << endl;
}

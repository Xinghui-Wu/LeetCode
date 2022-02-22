/**
 * 383. Ransom Note
 * 
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * Constraints:
 *   1 <= ransomNote.length, magazine.length <= 10^5
 *   ransomNote and magazine consist of lowercase English letters.
 * 
 * Difficulty: Easy
 * Related Topics: Hash Table, String, Counting
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        
        int magazine_count[26] = {0};

        for (char c: magazine)
        {
            magazine_count[c - 'a']++;
        }

        for (char c: ransomNote)
        {
            magazine_count[c - 'a']--;

            if (magazine_count[c - 'a'] < 0)
            {
                return false;
            }
        }
        
        return true;
    }
};


int main()
{
    string ransomNote = "aa";
    string magazine = "aab";

    Solution solution;
    bool constructible = solution.canConstruct(ransomNote, magazine);

    cout << constructible << endl;

    return 0;
}

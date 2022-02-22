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
        int ransom_note_count[26] = {0};
        int magazine_count[26] = {0};

        for (char c: ransomNote)
        {
            ransom_note_count[c - 'a']++;
        }

        for (char c: magazine)
        {
            magazine_count[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (ransom_note_count[i] > magazine_count[i])
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

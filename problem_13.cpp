/**
 * 13. Roman to Integer
 * 
 * Roman numerals are represented by seven different symbols: I (1), V (5), X (10), L (50), C (100), D (500) and M (1000).
 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *   I can be placed before V (5) and X (10) to make 4 and 9. 
 *   X can be placed before L (50) and C (100) to make 40 and 90. 
 *   C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 * 
 * Constraints:
 *   1 <= s.length <= 15
 *   s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 *   It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 * 
 * Difficulty: Easy
 * Related Topics: Hash Table, Math, String
 */
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman_int_map;
        roman_int_map['I'] = 1;
        roman_int_map['V'] = 5;
        roman_int_map['X'] = 10;
        roman_int_map['L'] = 50;
        roman_int_map['C'] = 100;
        roman_int_map['D'] = 500;
        roman_int_map['M'] = 1000;

        // The last roman character should always be added.
        int roman_int = roman_int_map[s[s.length() - 1]];
        
        // The corresponding value of the current and the next roman character.
        int current;
        int next;

        for (size_t i = 0; i < s.length() - 1; i++)
        {
            current = roman_int_map[s[i]];
            next = roman_int_map[s[i + 1]];

            // Compare the current roman character to the next one to decide to add or subtract the value.
            if (current < next)
            {
                roman_int -= current;
            }
            else
            {
                roman_int += current;
            }
        }
        
        return roman_int;
    }
};


int main()
{
    string s = "MCMXCIV";

    Solution solution;
    int inverse = solution.romanToInt(s);

    cout << inverse << endl;

    return 0;
}

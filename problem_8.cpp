/**
 * 8. String to Integer (atoi)
 * 
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
 * The algorithm for myAtoi(string s) is as follows:
 *   1. Read in and ignore any leading whitespace.
 *   2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
 *   3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
 *   4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
 *   5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
 *   6. Return the integer as the final result.
 * 
 * Note:
 *   Only the space character ' ' is considered a whitespace character.
 *   Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 * 
 * Constraints:
 *   0 <= s.length <= 200
 *   s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
 * 
 * Difficulty: Medium
 * Related Topics: String
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int myAtoi(string s)
    {
        int value = 0;

        // Read in and ignore any leading whitespace.
        int start_index = 0;

        while (start_index < s.size() && s[start_index] == ' ')
        {
            start_index++;
        }

        // Determine if the final result is negative or positive.
        bool is_negative = false;

        if (s[start_index] == '-')
        {
            is_negative = true;
            start_index++;
        }
        else if (s[start_index] == '+')
        {
            start_index++;
        }
        
        // Read in next the characters until the next non-digit character or the end of the input is reached.
        int end_index = start_index;

        while (end_index < s.size() && s[end_index] >= '0' && s[end_index] <= '9')
        {
            end_index++;
        }

        // Intercept the valid portion of the string.
        s = s.substr(start_index, end_index - start_index);

        for (char digit: s)
        {
            if (value > INT32_MAX / 10 || value == INT32_MAX / 10 && digit > '7')
            {
                if (!is_negative)
                {
                    return INT32_MAX;
                }
                else
                {
                    return INT32_MIN;
                }
            }
            
            value *= 10;
            value += digit - '0';
        }
        
        if (is_negative)
        {
            value *= -1;
        }
        
        return value;
    }
};


int main()
{
    string s = "-91283472332";

    Solution solution;
    int value = solution.myAtoi(s);

    cout << value << endl;

    return 0;
}

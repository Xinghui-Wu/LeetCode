/**
 * 9. Palindrome Number
 * 
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
 * 
 * Constraints:
 *   -2^31 <= x <= 2^31 - 1
 * 
 * Difficulty: Easy
 * Related Topics: Math
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    bool isPalindrome(int x)
    {
        // All negative integers are not palindrome numbers.
        if (x < 0)
        {
            return false;
        }

        // All positive integers with the last digit being 0 are not palindrome numbers.
        if (x != 0 && x % 10 == 0)
        {
            return false;
        }

        int inverse = 0;

        // Reverse half of the given integer.
        while (x > inverse)
        {
            inverse = 10 * inverse + x % 10;
            x /= 10;
        }

        return x == inverse || x == inverse / 10;
    }
};


int main()
{
    int x = -1;

    Solution solution;
    int inverse = solution.isPalindrome(x);
    
    cout << inverse << endl;

    return 0;
}

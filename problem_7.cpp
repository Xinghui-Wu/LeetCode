/**
 * 7. Reverse Integer
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * 
 * Constraints:
 *   -2^31 <= x <= 2^31 - 1
 * 
 * Difficulty: Medium
 * Related Topics: Math
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int reverse(int x)
    {
        int inverse = 0;
        int digit;

        while (x != 0)
        {
            digit = x % 10;
            
            if (inverse > 214748364 || inverse == 214748364 && digit > 7)
            {
                return 0;
            }
            if (inverse < -214748364 || inverse == -214748364 && digit < -8)
            {
                return 0;
            }

            inverse = 10 * inverse + digit;
            x /= 10;
        }
        
        return inverse;
    }
};


int main()
{
    int x = 123;

    Solution solution;
    int inverse = solution.reverse(x);
    
    cout << inverse << endl;

    return 0;
}

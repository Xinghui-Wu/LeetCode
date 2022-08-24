/**
 * 326. Power of Three
 * 
 * Given an integer n, return true if it is a power of three. Otherwise, return false.
 * An integer n is a power of three, if there exists an integer x such that n == 3^x.
 * 
 * Constraints:
 *   -2^31 <= n <= 2^31 - 1
 * 
 * Follow up:
 *   Could you solve it without loops/recursion?
 * 
 * Difficulty: Easy
 * Related Topics: Math, Recursion
 */
#include <iostream>
#include <cmath>

using namespace std;


class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // Only positive number can be a power of three.
        if (n > 0)
        {
            int x = log(n) / log(3);
            
            // Consider the computing accuracy.
            if (pow(3, x) == n || pow(3, x + 1) == n)
            {
                return true;
            }
        }

        return false;
    }
};


int main()
{
    int n = 243;

    Solution solution;
    bool is_power_of_three = solution.isPowerOfThree(n);

    cout << is_power_of_three << endl;

    return 0;
}

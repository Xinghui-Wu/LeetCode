/**
 * 69. Sqrt(x)
 * 
 * Given a non-negative integer x, compute and return the square root of x.
 * Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
 * 
 * Note:
 *   You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
 * 
 * Constraints:
 *   0 <= x <= 2^31 - 1
 * 
 * Difficulty: Easy
 * Related Topics: Math, Binary Search
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
        {
            return x;
        }

        int sqrt;
        int left = 1;
		int right = x;

        // Binary Search
        while (left <= right)
        {
            // Prevent the integer overflow.
            sqrt = left + (right - left) / 2;

            if (x / sqrt < sqrt)
            {
                right = sqrt - 1;
            }
            else if (x / (sqrt + 1) < sqrt + 1)
            {
                return sqrt;
            }
            else
            {
                left = sqrt + 1;
            }
        }
        
        return 0;
    }
};


int main()
{
    int x = 8;

    Solution solution;
    int sqrt = solution.mySqrt(x);

    cout << sqrt << endl;

    return 0;
}

/**
 * 371. Sum of Two Integers
 * 
 * Given two integers a and b, return the sum of the two integers without using the operators + and -.
 * 
 * Constraints:
 *   -1000 <= a, b <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Math, Bit Manipulation
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int getSum(int a, int b)
    {
        unsigned int carry;

        while (b != 0)
        {
            carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }

        return a;
    }
};


int main()
{
    int a = -1;
    int b = 1;

    Solution solution;
    int sum = solution.getSum(a, b);

    cout << sum << endl;

    return 0;
}

/**
 * 190. Reverse Bits
 * 
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Note:
 *   Note that in some languages, such as Java, there is no unsigned integer type.
 *   In this case, the input will be given as a signed integer type.
 *   It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
 *   In Java, the compiler represents the signed integers using 2's complement notation.
 * 
 * Constraints:
 *   The input must be a binary string of length 32.
 * 
 * Follow up:
 *   If this function is called many times, how would you optimize it?
 * 
 * Difficulty: Easy
 * Related Topics: Divide and Conquer, Bit Manipulation
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t reversed_n = 0;

        for (size_t i = 0; i < 32; i++)
        {
            reversed_n <<= 1;
            reversed_n |= n & 1;
            n >>= 1;
        }
        
        return reversed_n;
    }
};


int main()
{
    uint32_t n = 0b00000010100101000001111010011100;

    Solution solution;
    uint32_t reversed_n = solution.reverseBits(n);

    cout << reversed_n << endl;

    return 0;
}

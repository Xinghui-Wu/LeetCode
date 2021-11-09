/**
 * 191. Number of 1 Bits
 * 
 * Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
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
 * Related Topics: Bit Manipulation
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int hamming_weight = 0;

        while (n)
        {
            // Change the lowest bit of the binary representation of n as 1 to 0.
            n &= (n - 1);
            hamming_weight++;
        }

        return hamming_weight;
    }
};


int main()
{
    uint32_t n = 0b11111111111111111111111111111101;

    Solution solution;
    int hamming_weight = solution.hammingWeight(n);

    cout << hamming_weight << endl;

    return 0;
}

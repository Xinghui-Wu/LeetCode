/**
 * 67. Add Binary
 * 
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * Constraints:
 *   1 <= a.length, b.length <= 10^4
 *   a and b consist only of '0' or '1' characters.
 *   Each string does not contain leading zeros except for the zero itself.
 * 
 * Difficulty: Easy
 * Related Topics: Math, String, Bit Manipulation, Simulation
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    string addBinary(string a, string b)
    {
        string sum;

        // If the two input strings, a and b, are of different lengths, make them the same by zero padding.
        if (a.size() != b.size())
        {
            string padding = "";

            for (size_t i = 0; i < abs(int(a.size()) - int(b.size())); i++)
            {
                padding.push_back('0');
            }

            if (a.size() < b.size())
            {
                a = padding.append(a);
            }
            else
            {
                b = padding.append(b);
            }
        }

        char carry = '0';
        char current_sum;

        for (int i = a.size() - 1; i >= 0; i--)
        {
            current_sum = a[i] + b[i] + carry - 96;

            if (current_sum == '2')
            {
                sum.insert(0, 1, '0');
                carry = '1';
            }
            else if (current_sum == '3')
            {
                sum.insert(0, 1, '1');
                carry = '1';
            }
            else
            {
                sum.insert(0, 1, current_sum);
                carry = '0';
            }
        }

        if (carry == '1')
        {
            sum.insert(0, 1, '1');
        }

        return sum;
    }
};


int main()
{
    string a = "1010";
    string b = "1011";

    Solution solution;
    string sum = solution.addBinary(a, b);

    cout << sum << endl;

    return 0;
}

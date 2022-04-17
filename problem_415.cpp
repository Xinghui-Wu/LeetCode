/**
 * 415. Add Strings
 * 
 * Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
 * You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
 * You must also not convert the inputs to integers directly.
 * 
 * Constraints:
 *   1 <= num1.length, num2.length <= 10^4
 *   num1 and num2 consist of only digits.
 *   num1 and num2 don't have any leading zeros except for the zero itself.
 * 
 * Difficulty: Easy
 * Related Topics: Math, String, Simulation
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int length1 = num1.size();
        int length2 = num2.size();

        // If the two input strings, a and b, are of different lengths, make them the same by zero padding.
        if (length1 != length2)
        {
            string padding(abs(length1 - length2), '0');

            if (length1 < length2)
            {
                num1 = padding.append(num1);
            }
            else
            {
                num2 = padding.append(num2);
            }
        }

        string sum(num1.size(), '0');

        char carry = '0';
        char current_sum;

        for (int i = num1.size(); i >= 0; i--)
        {
            current_sum = num1[i] + num2[i] + carry - 96;

            if (current_sum <= '9')
            {
                carry = '0';
                sum[i] = current_sum;
            }
            else
            {
                carry = '1';
                sum[i] = current_sum - 10;
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
    string num1 = "456";
    string num2 = "77";

    Solution solution;
    string sum = solution.addStrings(num1, num2);

    cout << sum << endl;

    return 0;
}

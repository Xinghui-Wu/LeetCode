/**
 * 66. Plus One
 * 
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
 * The digits are ordered from most significant to least significant in left-to-right order.
 * The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 * 
 * Constraints:
 *   1 <= digits.length <= 100
 *   0 <= digits[i] <= 9
 *   digits does not contain any leading 0's.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Math
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        // Iterate through the array from the last element until a digit is less than 9.
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;

                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }

        // If the overflow occurs, insert 1 at the beginning.
        if (digits[0] == 0)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};


int main()
{
    vector<int> digits = {1, 2, 3};

    Solution solution;
    vector<int> plus_one = solution.plusOne(digits);

    for (size_t i = 0; i < plus_one.size(); i++)
    {
        cout << plus_one[i] << endl;
    }

    return 0;
}

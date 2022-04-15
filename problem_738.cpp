/**
 * 738. Monotone Increasing Digits
 * 
 * An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
 * Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
 * 
 * Constraints:
 *   0 <= n <= 10^9
 * 
 * Difficulty: Medium
 * Related Topics: Math, Greedy
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string monotone_number = to_string(n);
        
        int flag = monotone_number.size();

        for (int i = monotone_number.size() - 1; i > 0; i--)
        {
            if (monotone_number[i - 1] > monotone_number[i])
            {
                flag = i;
                monotone_number[i - 1]--;
            }
        }
        
        for (int i = flag; i < monotone_number.size(); i++)
        {
            monotone_number[i] = '9';
        }
        
        return stoi(monotone_number);
    }
};


int main()
{
    int n = 332;

    Solution solution;
    int monotone_number = solution.monotoneIncreasingDigits(n);

    cout << monotone_number << endl;

    return 0;
}

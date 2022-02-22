/**
 * 202. Happy Number
 * 
 * Write an algorithm to determine if a number n is happy.
 * A happy number is a number defined by the following process:
 *   Starting with any positive integer, replace the number by the sum of the squares of its digits.
 *   Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 *   Those numbers for which this process ends in 1 are happy.
 * Return true if n is a happy number, and false if not.
 * 
 * Constraints:
 *   1 <= n <= 2^31 - 1
 * 
 * Difficulty: Easy
 * Related Topics: Hash Table, Math, Two Pointers
 */
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> nums_set;

        int sum;
        int digit;

        while (n != 1)
        {
            sum = 0;

            while (n != 0)
            {
                digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            
            if (nums_set.count(sum) > 0)
            {
                return false;
            }
            
            nums_set.insert(sum);
            n = sum;
        }
        
        return true;
    }
};


int main()
{
    int n = 2;

    Solution solution;
    bool is_happy = solution.isHappy(n);

    cout << is_happy << endl;

    return 0;
}

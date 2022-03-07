/**
 * 509. Fibonacci Number
 * 
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
 * That is, F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2), for n > 1.
 * Given n, calculate F(n).
 * 
 * Constraints:
 *   0 <= n <= 30
 * 
 * Difficulty: Easy
 * Related Topics: Math, Dynamic Programming, Recursion, Memoization
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        int num1 = 0;
        int num2 = 1;
        int fibonacci_number;
        
        for (int i = 2; i <= n; i++)
        {
            fibonacci_number = num1 + num2;
            num1 = num2;
            num2 = fibonacci_number;
        }
        
        return fibonacci_number;
    }
};


int main()
{
    int n = 30;

    Solution solution;
    int fibonacci_number = solution.fib(n);

    cout << fibonacci_number << endl;

    return 0;
}

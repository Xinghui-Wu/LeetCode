/**
 * 70. Climbing Stairs
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Constraints:
 *   1 <= n <= 45
 * 
 * Difficulty: Easy
 * Related Topics: Math, Dynamic Programming, Memoization
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        // The result of climbStairs(n).
        int num_ways;
        // The result of climbStairs(n - 1).
        int num_ways_1 = 3;
        // The result of climbStairs(n - 2).
        int num_ways_2 = 2;

        // climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2)
        for (size_t i = 4; i <= n; i++)
        {
            num_ways = num_ways_1 + num_ways_2;

            num_ways_2 = num_ways_1;
            num_ways_1 = num_ways;
        }
        
        return num_ways;
    }
};


int main()
{
    int n = 45;

    Solution solution;
    int num_ways = solution.climbStairs(n);

    cout << num_ways << endl;
    
    return 0;
}

/**
 * 343. Integer Break
 * 
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
 * Return the maximum product you can get.
 * 
 * Constraints:
 *   2 <= n <= 58
 * 
 * Difficulty: Medium
 * Related Topics: Math, Dynamic Programming
 */
#include <iostream>

using namespace std;


class Solution
{
private:
    static int max_product_records[59];
    static int count;

public:
    int integerBreak(int n)
    {
        if (n <= count)
        {
            return max_product_records[n];
        }
        
        int product;

        for (int i = count + 1; i <= n; i++)
        {
            for (int j = 1; j <= i - 1; j++)
            {
                product = max(j, max_product_records[j]) * max(i - j, max_product_records[i - j]);

                if (max_product_records[i] < product)
                {
                    max_product_records[i] = product;
                }
            }
        }
        
        count = n;

        return max_product_records[n];
    }
};

int Solution::max_product_records[] = {0, 1, 1, 2, 4};
int Solution::count = 4;


int main()
{
    int n = 10;

    Solution solution;
    int max_product = solution.integerBreak(n);

    cout << max_product << endl;

    return 0;
}

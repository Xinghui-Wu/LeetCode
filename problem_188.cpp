/**
 * 188. Best Time to Buy and Sell Stock IV
 * 
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
 * Find the maximum profit you can achieve.
 * You may complete at most k transactions.
 * 
 * Note:
 *   You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 * Constraints:
 *   0 <= k <= 100
 *   0 <= prices.length <= 1000
 *   0 <= prices[i] <= 1000
 * 
 * Difficulty: Hard
 * Related Topics: Array, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        if (prices.size() == 0 || k == 0)
        {
            return 0;
        }
        
        int dp[2 * k];

        for (size_t j = 0; j < 2 * k; j += 2)
        {
            dp[j] = -prices[0];
            dp[j + 1] = 0;
        }

        for (size_t i = 1; i < prices.size(); i++)
        {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);

            for (size_t j = 2; j < 2 * k; j += 2)
            {
                dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
            }
        }
        
        return dp[2 * k - 1];
    }
};


int main()
{
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    Solution solution;
    int max_profit = solution.maxProfit(k, prices);

    cout << max_profit << endl;

    return 0;
}

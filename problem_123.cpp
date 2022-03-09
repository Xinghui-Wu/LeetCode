/**
 * 123. Best Time to Buy and Sell Stock III
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve.
 * You may complete at most two transactions.
 * 
 * Note:
 *   You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 * Constraints:
 *   1 <= prices.length <= 10^5
 *   0 <= prices[i] <= 10^5
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
    int maxProfit(vector<int>& prices)
    {
        int dp[4] = {-prices[0], 0, -prices[0], 0};

        for (size_t i = 1; i < prices.size(); i++)
        {
            // Buy the stock for the first time.
            dp[0] = max(dp[0], -prices[i]);
            // Sell the stock for the first time.
            dp[1] = max(dp[1], dp[0] + prices[i]);
            // Buy the stock for the second time.
            dp[2] = max(dp[2], dp[1] - prices[i]);
            // Sell the stock for the second time.
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        
        return dp[3];
    }
};


int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    Solution solution;
    int max_profit = solution.maxProfit(prices);

    cout << max_profit << endl;

    return 0;
}

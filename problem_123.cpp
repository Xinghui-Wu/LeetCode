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
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        for (size_t i = 1; i < prices.size(); i++)
        {
            // Buy the stock for the first time.
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            // Sell the stock for the first time.
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            // Buy the stock for the second time.
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            // Sell the stock for the second time.
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        
        return dp[prices.size() - 1][4];
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

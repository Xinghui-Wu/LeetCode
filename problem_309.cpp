/**
 * 309. Best Time to Buy and Sell Stock with Cooldown
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve.
 * You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
 *   After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
 * 
 * Note:
 *   You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 * Constraints:
 *   1 <= prices.length <= 5000
 *   0 <= prices[i] <= 1000
 * 
 * Difficulty: Medium
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
        if (prices.size() == 1)
        {
            return 0;
        }
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(0, prices[1] - prices[0]);

        for (size_t i = 2; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[prices.size() - 1][1];
    }
};


int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};

    Solution solution;
    int max_profit = solution.maxProfit(prices);

    cout << max_profit << endl;

    return 0;
}

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
        
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (size_t i = 1; i < prices.size(); i++)
        {
            // The stock has been bought.
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]);
            // The stock was sold two days ago and today is not cooldown day.
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            // The stock was sold today.
            dp[i][2] = dp[i - 1][0] + prices[i];
            // Today is cooldown day.
            dp[i][3] = dp[i - 1][2];
        }

        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
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

/**
 * 714. Best Time to Buy and Sell Stock with Transaction Fee
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
 * Find the maximum profit you can achieve.
 * You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
 * 
 * Note:
 *   You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 * Constraints:
 *   1 <= prices.length <= 5 * 10^4
 *   1 <= prices[i] < 5 * 10^4
 *   0 <= fee < 5 * 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Greedy
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int dp[2][2] = {{-prices[0], 0}, {0, 0}};

        for (size_t i = 1; i < prices.size(); i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i] - fee);
        }

        return dp[(prices.size() - 1) % 2][1];
    }
};


int main()
{
    vector<int> prices = {1, 3, 7, 5, 10, 3};
    int fee = 3;

    Solution solution;
    int max_profit = solution.maxProfit(prices, fee);

    cout << max_profit << endl;

    return 0;
}

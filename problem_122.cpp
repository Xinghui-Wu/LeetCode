/**
 * 122. Best Time to Buy and Sell Stock II
 * 
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 * On each day, you may decide to buy and/or sell the stock.
 * You can only hold at most one share of the stock at any time.
 * However, you can buy it then immediately sell it on the same day.
 * Find and return the maximum profit you can achieve.
 * 
 * Constraints:
 *   1 <= prices.length <= 3 * 10^4
 *   0 <= prices[i] <= 10^4
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
    int maxProfit(vector<int>& prices)
    {
        int max_profit = 0;

        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                max_profit += prices[i] - prices[i - 1];
            }
        }

        return max_profit;
    }
};


int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution solution;
    int max_profit = solution.maxProfit(prices);

    cout << max_profit << endl;

    return 0;
}

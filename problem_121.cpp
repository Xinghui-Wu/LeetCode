/**
 * 121. Best Time to Buy and Sell Stock
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Constraints:
 *   1 <= prices.length <= 10^5
 *   0 <= prices[i] <= 10^4
 * 
 * Difficulty: Easy
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
        int max_profit = 0;
        int min_price = prices[0];

        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
            else if (prices[i] - min_price > max_profit)
            {
                max_profit = prices[i] - min_price;
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

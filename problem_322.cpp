/**
 * 322. Coin Change
 * 
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * Constraints:
 *   1 <= coins.length <= 12
 *   1 <= coins[i] <= 2^31 - 1
 *   0 <= amount <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Breadth-First Search
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] < INT32_MAX)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        if (dp[amount] == INT32_MAX)
        {
            return -1;
        }
        
        return dp[amount];
    }
};


int main()
{
    vector<int> coins = {2};
    int amount = 3;

    Solution solution;
    int fewest = solution.coinChange(coins, amount);

    cout << fewest << endl;

    return 0;
}

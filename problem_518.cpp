/**
 * 518. Coin Change 2
 * 
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the number of combinations that make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return 0.
 * You may assume that you have an infinite number of each kind of coin.
 * The answer is guaranteed to fit into a signed 32-bit integer.
 * 
 * Constraints:
 *   1 <= coins.length <= 300
 *   1 <= coins[i] <= 5000
 *   All the values of coins are unique.
 *   0 <= amount <= 5000
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
    int change(int amount, vector<int>& coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};


int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    Solution solution;
    int num_combinations = solution.change(amount, coins);

    cout << num_combinations << endl;

    return 0;
}

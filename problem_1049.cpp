/**
 * 1049. Last Stone Weight II
 * 
 * You are given an array of integers stones where stones[i] is the weight of the ith stone.
 * We are playing a game with the stones.
 * On each turn, we choose any two stones and smash them together.
 * Suppose the stones have weights x and y with x <= y.
 * The result of this smash is:
 *   If x == y, both stones are destroyed, and
 *   If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
 * At the end of the game, there is at most one stone left.
 * Return the smallest possible weight of the left stone.
 * If there are no stones left, return 0.
 * 
 * Constraints:
 *   1 <= stones.length <= 30
 *   1 <= stones[i] <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        // Calculate the total weight of all stones.
        int sum = accumulate(stones.begin(), stones.end(), 0);

        // Try to divide the stones into two subsets equally.
        vector<int> dp(sum / 2 + 1);

        // The game problem can be converted into 0-1 bags.
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = sum / 2; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return (sum - dp[sum / 2]) - dp[sum / 2];
    }
};


int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    Solution solution;
    int last_weight = solution.lastStoneWeightII(stones);

    cout << last_weight << endl;

    return 0;
}

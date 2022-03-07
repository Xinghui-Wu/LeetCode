/**
 * 746. Min Cost Climbing Stairs
 * 
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
 * Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 * 
 * Constraints:
 *   2 <= cost.length <= 1000
 *   0 <= cost[i] <= 999
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
    int minCostClimbingStairs(vector<int>& cost)
    {
        if (cost.size() == 2)
        {
            return min(cost[0], cost[1]);
        }
        
        int cost1 = cost[0];
        int cost2 = cost[1];
        int min_cost;

        for (int i = 2; i < cost.size(); i++)
        {
            min_cost = min(cost1, cost2) + cost[i];
            cost1 = cost2;
            cost2 = min_cost;
        }
        
        return min(cost1, cost2);
    }
};


int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    Solution solution;
    int min_cost = solution.minCostClimbingStairs(cost);

    cout << min_cost << endl;

    return 0;
}

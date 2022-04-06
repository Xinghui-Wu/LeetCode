/**
 * 134. Gas Station
 * 
 * There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
 * You begin the journey with an empty tank at one of the gas stations.
 * Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
 * If there exists a solution, it is guaranteed to be unique.
 * 
 * Constraints:
 *   n == gas.length == cost.length
 *   1 <= n <= 10^5
 *   0 <= gas[i], cost[i] <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Greedy
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int start_index = 0;

        // Record the rest gas after one station.
        int rest = 0;
        // Record the overall difference between the gas supply and the cost.
        int sum = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            rest += gas[i] - cost[i];
            sum += gas[i] - cost[i];

            // If the current rest value is negative, the start index cannot be [0, i].
            if (rest < 0)
            {
                start_index = i + 1;
                rest = 0;
            }
        }
        
        if (sum < 0)
        {
            return -1;
        }

        return start_index;
    }
};


int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    Solution solution;
    int start_index = solution.canCompleteCircuit(gas, cost);

    cout << start_index << endl;

    return 0;
}

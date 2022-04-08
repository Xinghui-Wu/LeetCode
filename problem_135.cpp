/**
 * 135. Candy
 * 
 * There are n children standing in a line.
 * Each child is assigned a rating value given in the integer array ratings.
 * You are giving candies to these children subjected to the following requirements:
 *   Each child must have at least one candy.
 *   Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies you need to have to distribute the candies to the children.
 * 
 * Constraints:
 *   n == ratings.length
 *   1 <= n <= 2 * 10^4
 *   0 <= ratings[i] <= 2 * 10^4
 * 
 * Difficulty: Hard
 * Related Topics: Array, Greedy
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();

        if (n == 1)
        {
            return 1;
        }

        vector<int> candies(n);

        // Make sure that the right child get one more candy than the left child if needed.
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Make sure that the left child get one more candy than the right child if needed.
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), n);
    }
};


int main()
{
    vector<int> ratings = {1, 2, 2};

    Solution solution;
    int num_candies = solution.candy(ratings);

    cout << num_candies << endl;

    return 0;
}

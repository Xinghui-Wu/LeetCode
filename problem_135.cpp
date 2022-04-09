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

using namespace std;


class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int num_candies = 1;

        int increasing_length = 1;
        int decreasing_length = 0;
        int previous = 1;

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] >= ratings[i - 1])
            {
                decreasing_length = 0;
                previous = ratings[i] == ratings[i - 1] ? 1 : previous + 1;
                num_candies += previous;
                increasing_length = previous;
            }
            else
            {
                decreasing_length++;

                if (decreasing_length == increasing_length)
                {
                    decreasing_length++;
                }
                
                num_candies += decreasing_length;
                previous = 1;
            }
        }

        return num_candies;
    }
};


int main()
{
    vector<int> ratings = {1, 3, 5, 2, 3, 3};

    Solution solution;
    int num_candies = solution.candy(ratings);

    cout << num_candies << endl;

    return 0;
}

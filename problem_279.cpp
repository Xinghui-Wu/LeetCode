/**
 * 279. Perfect Squares
 * 
 * Given an integer n, return the least number of perfect square numbers that sum to n.
 * A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.
 * For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 * 
 * Constraints:
 *   1 <= n <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Math, Dynamic Programming, Breadth-First Search
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
private:
    static vector<int> num_squares_records;

public:
    int numSquares(int n)
    {
        if (n <= num_squares_records.size() - 1)
        {
            return num_squares_records[n];
        }

        for (int i = num_squares_records.size(); i <= n; i++)
        {
            int num_squares = i;

            for (int j = 1; j * j <= i; j++)
            {
                if (num_squares_records[i - j * j] < num_squares)
                {
                    num_squares = num_squares_records[i - j * j];
                }
            }
            
            num_squares_records.push_back(num_squares + 1);
        }
        
        return num_squares_records[n];
    }
};

vector<int> Solution::num_squares_records = {0, 1, 2, 3, 1};


int main()
{
    int n = 12;

    Solution solution;
    int num_squares = solution.numSquares(n);

    cout << num_squares << endl;
    
    return 0;
}

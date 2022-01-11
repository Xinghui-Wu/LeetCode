/**
 * 62. Unique Paths
 * 
 * There is a robot on an m x n grid.
 * The robot is initially located at the top-left corner (i.e., grid[0][0]).
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 * The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
 * 
 * Constraints:
 *   1 <= m, n <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Math, Dynamic Programming, Combinatorics
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int num_unique_paths[m][n];

        for (int i = 0; i < m; i++)
        {
            num_unique_paths[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            num_unique_paths[0][j] = 1;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                num_unique_paths[i][j] = num_unique_paths[i - 1][j] + num_unique_paths[i][j - 1];
            }
        }

        return num_unique_paths[m - 1][n - 1];
    }
};


int main()
{
    int m = 3;
    int n = 7;

    Solution solution;
    int num_unique_paths = solution.uniquePaths(m, n);

    cout << num_unique_paths << endl;;

    return 0;
}

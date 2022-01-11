/**
 * 63. Unique Paths II
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * Now consider if some obstacles are added to the grids.
 * How many unique paths would there be?
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 * 
 * Constraints:
 *   m == obstacleGrid.length
 *   n == obstacleGrid[i].length
 *   1 <= m, n <= 100
 *   obstacleGrid[i][j] is 0 or 1.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Matrix
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int num_unique_paths[m][n];

        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
            {
                num_unique_paths[i][0] = 1;
            }
            else
            {
                for (; i < m; i++)
                {
                    num_unique_paths[i][0] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0)
            {
                num_unique_paths[0][j] = 1;
            }
            else
            {
                for (; j < n; j++)
                {
                    num_unique_paths[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    num_unique_paths[i][j] = num_unique_paths[i - 1][j] + num_unique_paths[i][j - 1];
                }
                else
                {
                    num_unique_paths[i][j] = 0;
                }
            }
        }

        return num_unique_paths[m - 1][n - 1];
    }
};


int main()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    Solution solution;
    int num_unique_paths = solution.uniquePathsWithObstacles(obstacleGrid);

    cout << num_unique_paths << endl;

    return 0;
}

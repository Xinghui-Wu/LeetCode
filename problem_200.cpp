/**
 * 200. Number of Islands
 * 
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 * 
 * Constraints:
 *   m == grid.length
 *   n == grid[i].length
 *   1 <= m, n <= 300
 *   grid[i][j] is '0' or '1'.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int num_islands = 0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> neighbors;
        int x;
        int y;

        // Breadth-First Search
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    grid[i][j] == '0';
                    neighbors.push({i, j});

                    while (!neighbors.empty())
                    {
                        auto center = neighbors.front();
                        neighbors.pop();

                        x = center.first;
                        y = center.second;

                        if (x - 1 >= 0 && grid[x - 1][y] == '1')
                        {
                            grid[x - 1][y] = '0';
                            neighbors.push({x - 1, y});
                        }
                        if (x + 1 < m && grid[x + 1][y] == '1')
                        {
                            grid[x + 1][y] = '0';
                            neighbors.push({x + 1, y});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1')
                        {
                            grid[x][y - 1] = '0';
                            neighbors.push({x, y - 1});
                        }
                        if (y + 1 < n && grid[x][y + 1] == '1')
                        {
                            grid[x][y + 1] = '0';
                            neighbors.push({x, y + 1});
                        }
                    }
                }
            }
        }
        
        return num_islands;
    }
};


int main()
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, 
                                 {'1', '1', '0', '0', '0'}, 
                                 {'0', '0', '1', '0', '0'}, 
                                 {'0', '0', '0', '1', '1'}};
    
    Solution solution;
    int num_islands = solution.numIslands(grid);

    cout << num_islands << endl;

    return 0;
}

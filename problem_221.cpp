/**
 * 221. Maximal Square
 * 
 * Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 * 
 * Constraints:
 *   m == matrix.length
 *   n == matrix[i].length
 *   1 <= m, n <= 300
 *   matrix[i][j] is '0' or '1'.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Matrix
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int max_square = 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }

                    max_square = max(max_square, dp[i][j]);
                }
            }
        }

        return max_square * max_square;
    }
};


int main()
{
    // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, 
    //                                {'1', '0', '1', '1', '1'}, 
    //                                {'1', '1', '1', '1', '1'}, 
    //                                {'1', '0', '0', '1', '0'}};
    
    vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
    Solution solution;
    int max_square = solution.maximalSquare(matrix);

    cout << max_square << endl;

    return 0;
}

/**
 * 59. Spiral Matrix II
 * 
 * Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.
 * 
 * Constraints:
 *   1 <= n <= 20
 * 
 * Difficulty: Medium
 * Related Topics: Array, Matrix, Simulation
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int count = 1;
        
        while (count <= n * n)
        {
            for (int j = left; j <= right && count <= n * n; j++)
            {
                matrix[top][j] = count++;
            }
            for (int i = top + 1; i <= bottom && count <= n * n; i++)
            {
                matrix[i][right] = count++;
            }
            for (int j = right - 1; j >= left && count <= n * n; j--)
            {
                matrix[bottom][j] = count++;
            }
            for (int i = bottom - 1; i >= top + 1 && count <= n * n; i--)
            {
                matrix[i][left] = count++;
            }

            top += 1;
            bottom -= 1;
            left += 1;
            right -= 1;
        }

        return matrix;
    }
};


int main()
{
    int n = 5;

    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(n);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        
        cout << endl;
    }

    return 0;
}

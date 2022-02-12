/**
 * 54. Spiral Matrix
 * 
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * Constraints:
 *   m == matrix.length
 *   n == matrix[i].length
 *   1 <= m, n <= 10
 *   -100 <= matrix[i][j] <= 100
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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> spiral_order(m * n);

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        int count = 0;
        
        while (count < m * n)
        {
            for (int j = left; j <= right && count < m * n; j++)
            {
                spiral_order[count++] = matrix[top][j];
            }
            for (int i = top + 1; i <= bottom && count < m * n; i++)
            {
                spiral_order[count++] = matrix[i][right];
            }
            for (int j = right - 1; j >= left && count < m * n; j--)
            {
                spiral_order[count++] = matrix[bottom][j];
            }
            for (int i = bottom - 1; i >= top + 1 && count < m * n; i--)
            {
                spiral_order[count++] = matrix[i][left];
            }

            top += 1;
            bottom -= 1;
            left += 1;
            right -= 1;
        }

        return spiral_order;
    }
};


int main()
{
    // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> matrix = {{7}, {9}, {6}};

    Solution solution;
    vector<int> spiral_order = solution.spiralOrder(matrix);

    for (size_t i = 0; i < spiral_order.size(); i++)
    {
        cout << spiral_order[i] << endl;
    }
    
    return 0;
}

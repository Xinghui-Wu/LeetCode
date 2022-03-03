/**
 * 52. N-Queens II
 * 
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 * 
 * Constraints:
 *   1 <= n <= 9
 * 
 * Difficulty: Hard
 * Related Topics: Array, Backtracking
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int totalNQueens(int n)
    {
        int num_solutions = 0;
        vector<string> chessboard(n, string(n, '.'));

        backtracking(n, num_solutions, chessboard, 0);
        
        return num_solutions;
    }


    void backtracking(int n, int& num_solutions, vector<string>& chessboard, int row)
    {
        if (row == n)
        {
            num_solutions++;
            
            return;
        }
        
        for (int column = 0; column < n; column++)
        {
            if (valid(chessboard, row, column, n))
            {
                chessboard[row][column] = 'Q';
                backtracking(n, num_solutions, chessboard, row + 1);
                chessboard[row][column] = '.';
            }
        }
    }


    bool valid(vector<string>& chessboard, int row, int column, int n)
    {
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][column] == 'Q')
            {
                return false;
            }
        }
        
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        
        for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
};


int main()
{
    int n = 4;

    Solution solution;
    int num_solutions = solution.totalNQueens(n);

    cout << num_solutions << endl;
    
    return 0;
}

/**
 * 51. N-Queens
 * 
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
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
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> n_queens;
        vector<string> chessboard(n, string(n, '.'));

        backtracking(n, n_queens, chessboard, 0);

        return n_queens;
    }


    void backtracking(int n, vector<vector<string>>& n_queens, vector<string>& chessboard, int row)
    {
        if (row == n)
        {
            n_queens.push_back(chessboard);
            
            return;
        }
        
        for (int column = 0; column < n; column++)
        {
            if (valid(chessboard, row, column, n))
            {
                chessboard[row][column] = 'Q';
                backtracking(n, n_queens, chessboard, row + 1);
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
    vector<vector<string>> n_queens = solution.solveNQueens(n);

    for (size_t i = 0; i < n_queens.size(); i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << n_queens[i][j] << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}

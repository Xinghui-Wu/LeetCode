/**
 * 37. Sudoku Solver
 * 
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * A sudoku solution must satisfy all of the following rules:
 *   Each of the digits 1-9 must occur exactly once in each row.
 *   Each of the digits 1-9 must occur exactly once in each column.
 *   Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * The '.' character indicates empty cells.
 * 
 * Constraints:
 *   board.length == 9
 *   board[i].length == 9
 *   board[i][j] is a digit or '.'.
 *   It is guaranteed that the input board has only one solution.
 * 
 * Difficulty: Hard
 * Related Topics: Array, Backtracking, Matrix
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        backtracking(board);
    }


    bool backtracking(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (valid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (backtracking(board))
                            {
                                return true;
                            }
                            
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        
        return true;
    }


    bool valid(vector<vector<char>>& board, int row, int column, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][column] == c)
            {
                return false;
            }
        }

        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == c)
            {
                return false;
            }
        }

        int sub_row = 3 * (row / 3);
        int sub_column = 3 * (column / 3);
        
        for (int i = sub_row; i < sub_row + 3; i++)
        {
            for (int j = sub_column; j < sub_column + 3; j++)
            {
                if (board[i][j] == c)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};


int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    
    Solution solution;
    solution.solveSudoku(board);

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            cout << board[i][j] << '\t';
        }

        cout << endl;
    }
    
    return 0;
}

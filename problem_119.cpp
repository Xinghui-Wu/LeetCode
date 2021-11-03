/**
 * 119. Pascal's Triangle II
 * 
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown.
 * 
 * Constraints:
 *   0 <= rowIndex <= 33
 * 
 * Difficulty: Easy
 * Related Topics: Array, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row_val_list(rowIndex + 1, 1);

        long combinatorial_number;

        for (size_t i = 1; i < rowIndex; i++)
        {
            combinatorial_number = (long) row_val_list[i - 1] * (rowIndex + 1 - i) / i;
            row_val_list[i] = (int) combinatorial_number;
        }

        return row_val_list;
    }
};


int main()
{
    int rowIndex = 4;

    Solution solution;
    vector<int> row_val_list = solution.getRow(rowIndex);

    for (size_t i = 0; i < row_val_list.size(); i++)
    {
        cout << row_val_list[i] << endl;
    }

    return 0;
}

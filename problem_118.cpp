/**
 * 118. Pascal's Triangle
 * 
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown.
 * 
 * Constraints:
 *   1 <= numRows <= 30
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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal_triangle = {{1}};

        for (size_t i = 1; i < numRows; i++)
        {
            vector<int> row_val_list = {1};

            for (size_t j = 1; j < i; j++)
            {
                row_val_list.push_back(pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j]);
            }

            row_val_list.push_back(1);
            
            pascal_triangle.push_back(row_val_list);
        }

        return pascal_triangle;
    }
};


int main()
{
    int numRows = 5;

    Solution solution;
    vector<vector<int>> pascal_triangle = solution.generate(numRows);

    for (size_t i = 0; i < pascal_triangle.size(); i++)
    {
        for (size_t j = 0; j < pascal_triangle[i].size(); j++)
        {
            cout << pascal_triangle[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}

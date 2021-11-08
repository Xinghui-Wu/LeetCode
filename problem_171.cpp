/**
 * 171. Excel Sheet Column Number
 * 
 * Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * Constraints:
 *   1 <= columnTitle.length <= 7
 *   columnTitle consists only of uppercase English letters.
 *   columnTitle is in the range ["A", "FXSHRXW"].
 * 
 * Difficulty: Easy
 * Related Topics: Math, String
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int column_number = 0;

        for (size_t i = 0; i < columnTitle.size(); i++)
        {
            column_number *= 26;
            column_number += columnTitle[i] - 64;
        }
        
        return column_number;
    }
};


int main()
{
    string columnTitle = "FXSHRXW";

    Solution solution;
    int column_number = solution.titleToNumber(columnTitle);

    cout << column_number << endl;

    return 0;
}

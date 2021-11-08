/**
 * 168. Excel Sheet Column Title
 * 
 * Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
 * 
 * Constraints:
 *   1 <= columnNumber <= 2^31 - 1
 * 
 * Difficulty: Easy
 * Related Topics: Math, String
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string column_title;
        
        while (columnNumber != 0)
        {
            columnNumber--;

            column_title.insert(0, 1, 'A' + columnNumber % 26);

            columnNumber /= 26;
        }

        return column_title;
    }
};


int main()
{
    int columnNumber = 2147483647;

    Solution solution;
    string column_title = solution.convertToTitle(columnNumber);

    cout << column_title << endl;

    return 0;
}

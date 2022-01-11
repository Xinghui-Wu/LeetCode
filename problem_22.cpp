/**
 * 22. Generate Parentheses
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * Constraints:
 *   1 <= n <= 8
 * 
 * Difficulty: Medium
 * Related Topics: String, Dynamic Programming, Backtracking
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
private:
    static vector<string> parentheses_records[9];
    static int count;

public:
    vector<string> generateParenthesis(int n)
    {
        if (n <= count)
        {
            return parentheses_records[n];
        }
        
        // The relationship between subproblems is defined as (left_parentheses)right_parentheses.
        vector<string> left_parentheses;
        vector<string> right_parentheses;

        string left_string;
        string right_string;
        string current_string;
        
        for (int i = count + 1; i <= n; i++)
        {
            vector<string> parentheses;

            for (int left = 0; left <= i - 1; left++)
            {
                left_parentheses = parentheses_records[left];
                right_parentheses = parentheses_records[i - 1 - left];

                for (int j = 0; j < left_parentheses.size(); j++)
                {
                    for (int k = 0; k < right_parentheses.size(); k++)
                    {
                        left_string = left_parentheses[j];
                        right_string = right_parentheses[k];
                        current_string = "(" + left_string + ")" + right_string;

                        parentheses.push_back(current_string);
                    }
                }
            }

            parentheses_records[i] = parentheses;
        }

        count = n;

        return parentheses_records[n];
    }
};

vector<string> Solution::parentheses_records[] = {{""}, {"()"}, {"(())", "()()"}};
int Solution::count = 2;


int main()
{
    Solution solution;

    for (int n = 1; n <= 8; n++)
    {
        vector<string> parentheses = solution.generateParenthesis(n);

        for (size_t j = 0; j < parentheses.size(); j++)
        {
            cout << parentheses[j] << '\t';
        }
        cout << endl;
    }
    
    return 0;
}

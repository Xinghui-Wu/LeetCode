/**
 * 131. Palindrome Partitioning
 * 
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * A palindrome string is a string that reads the same backward as forward.
 * 
 * Constraints:
 *   1 <= s.length <= 16
 *   s contains only lowercase English letters.
 * 
 * Difficulty: Medium
 * Related Topics: String, Dynamic Programming, Backtracking
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> palindromes;
        vector<string> path;

        backtracking(s, palindromes, path, 0);

        return palindromes;
    }


    void backtracking(string& s, vector<vector<string>>& palindromes, vector<string>& path, int index)
    {
        if (index >= s.size())
        {
            palindromes.push_back(path);

            return;
        }

        string sub_str;
        
        for (int i = index + 1; i <= s.size(); i++)
        {
            sub_str = s.substr(index, i - index);
            
            if (is_palindrome(sub_str))
            {
                path.push_back(sub_str);
                backtracking(s, palindromes, path, i);
                path.pop_back();
            }
        }
    }


    bool is_palindrome(string s)
    {
        // Traverse the input string with two pointers.
        int i = 0;
        int j = s.size() - 1;

        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};


int main()
{
    string s = "aab";

    Solution solution;
    vector<vector<string>> palindromes = solution.partition(s);

    for (size_t i = 0; i < palindromes.size(); i++)
    {
        for (size_t j = 0; j < palindromes[i].size(); j++)
        {
            cout << palindromes[i][j] << '\t';
        }
        
        cout << endl;
    }
    
    return 0;
}

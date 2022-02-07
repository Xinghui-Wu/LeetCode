/**
 * 17. Letter Combinations of a Phone Number
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * Return the answer in any order.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Note that 1 does not map to any letters.
 * 
 * Constraints:
 *   0 <= digits.length <= 4
 *   digits[i] is a digit in the range ['2', '9'].
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, String, Backtracking
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
private:
    static vector<vector<char>> letters;

public:
    vector<string> letterCombinations(string digits)
    {
        int capacity = 1;

        for (size_t i = 0; i < digits.size(); i++)
        {
            capacity *= letters[digits[i] - '2'].size();
        }

        if (capacity == 1)
        {
            capacity = 0;
        }

        vector<string> letter_combinations(capacity);

        int num_letters;
        int num_groups = 1;
        int interval;

        for (size_t i = 0; i < digits.size(); i++)
        {
            num_letters = letters[digits[i] - '2'].size();
            interval = capacity / num_letters / num_groups;

            for (size_t j = 0; j < num_groups; j++)
            {
                for (size_t k = 0; k < interval; k++)
                {
                    for (size_t l = 0; l < num_letters; l++)
                    {
                        letter_combinations[num_letters * interval * j + interval * l + k].push_back(letters[digits[i] - '2'][l]);
                    }
                }
            }

            num_groups *= num_letters;
        }
        
        return letter_combinations;
    }
};

vector<vector<char>> Solution::letters = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                          {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                          {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                          {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};


int main()
{
    string digits = "234";

    Solution solution;
    vector<string> letter_combinations = solution.letterCombinations(digits);

    for (size_t i = 0; i < letter_combinations.size(); i++)
    {
        cout << letter_combinations[i] << endl;
    }
    
    return 0;
}

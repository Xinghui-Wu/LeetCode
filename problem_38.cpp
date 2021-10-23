/**
 * 38. Count and Say
 * 
 * The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
 *   countAndSay(1) = "1"
 *   countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
 * To determine how you "say" a digit string, split it into the minimal digit of groups so that each group is a contiguous section all of the same character.
 * Then for each group, say the digit of characters, then say the character.
 * To convert the saying into a digit string, replace the counts with a digit and concatenate every saying.
 * Given a positive integer n, return the nth term of the count-and-say sequence.
 * 
 * Constraints:
 *   1 <= n <= 30
 * 
 * Difficulty: Medium
 * Related Topics: String
 */
#include <iostream>

using namespace std;


class Solution
{
public:
    string countAndSay(int n)
    {
        // The previous and current elements in the count-and-say sequence.
        string previous = "1";
        string current;

        // The digit at the current position and the number of its consecutive occurrences.
        char digit;
        char length;

        // Calculate new results of the count-and-say sequence.
        for (size_t i = 1; i < n; i++)
        {
            current = "";

            digit = previous[0];
            length = '1';

            for (size_t j = 1; j < previous.size(); j++)
            {
                if (previous[j] == digit)
                {
                    length++;
                }
                else
                {
                    current.push_back(length);
                    current.push_back(digit);

                    digit = previous[j];
                    length = '1';
                }
            }

            current.push_back(length);
            current.push_back(digit);

            previous = current;
        }
        
        return current;
    }
};


int main()
{
    Solution solution;

    for (size_t n = 1; n <= 30; n++)
    {
        string count_and_say = solution.countAndSay(n);
        cout << n << '\t' << count_and_say << endl;
    }
    
    return 0;
}

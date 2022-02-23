/**
 * 344. Reverse String
 * 
 * Write a function that reverses a string.
 * The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * Constraints:
 *   1 <= s.length <= 10^5
 *   s[i] is a printable ascii character.
 * 
 * Difficulty: Easy
 * Related Topics: Two Pointers, String, Recursion
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int i = 0;
        int j = s.size() - 1;

        char temp;

        while (i < j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            
            i++;
            j--;
        }
    }
};


int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution solution;
    solution.reverseString(s);

    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }
    
    return 0;
}

/**
 * 76. Minimum Window Substring
 * 
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
 * If there is no such substring, return the empty string "".
 * The testcases will be generated such that the answer is unique.
 * A substring is a contiguous sequence of characters within the string.
 * 
 * Constraints:
 *   m == s.length
 *   n == t.length
 *   1 <= m, n <= 10^5
 *   s and t consist of uppercase and lowercase English letters.
 * 
 * Follow up:
 *   Could you find an algorithm that runs in O(m + n) time?
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, String, Sliding Window
 */
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    string minWindow(string s, string t)
    {
        // Use HashMap to record the characters in two strings.
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for (char c: t)
        {
            t_map[c]++;
        }
        
        // Use two pointers for the sliding window.
        int left = 0;
        int right = 0;

        // Record the left index and the length of the min window.
        int min_window_left = -1;
        int min_window_length = INT32_MAX;

        while (right < s.size())
        {
            // Only take the characters that appear in t into account.
            if (t_map.count(s[right]) > 0)
            {
                s_map[s[right]]++;
            }
            
            // If now the window contains all the characters in t, narrow down the window by updating the left pointer.
            while (check(s_map, t_map) && left <= right)
            {
                // Update the info of the min window.
                if (right - left + 1 < min_window_length)
                {
                    min_window_left = left;
                    min_window_length = right - left + 1;
                }
                
                if (t_map.count(s[left]) > 0)
                {
                    s_map[s[left]]--;
                }

                left++;
            }

            // Expand the window by updating the right pointer.
            right++;
        }
        
        if (min_window_left == -1)
        {
            return "";
        }
        
        return s.substr(min_window_left, min_window_length);
    }


    bool check(unordered_map<char, int>& s_map, unordered_map<char, int>& t_map)
    {
        for (const auto& p: t_map)
        {
            if (s_map[p.first] < p.second)
            {
                return false;
            }
        }
        
        return true;
    }
};


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution solution;
    string min_window = solution.minWindow(s, t);

    cout << min_window << endl;

    return 0;
}

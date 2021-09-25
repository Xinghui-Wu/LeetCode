/**
 * 14. Longest Common Prefix
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * 
 * Constraints:
 *   1 <= strs.length <= 200
 *   0 <= strs[i].length <= 200
 *   strs[i] consists of only lower-case English letters.
 * 
 * Difficulty: Easy
 * Related Topics: String
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        // Find the shortest string amongst the array of strings.
		string shortest_string = strs[0];

        for (size_t i = 1; i < strs.size(); i++)
        {
            if (strs[i].length() < shortest_string.length())
            {
                shortest_string = strs[i];
            }
            
        }

		// The main idea is to get a prefix of the shortest string at a time and check if it is a common prefix.
		// Since the shortest string has n prefixes (n is the length of the shortest string) and the array has N strings, checking them one by one is time-consuming.
		// Thus, get a prefix of the shortest string at a time based on the thought of Binary Search to speed up the search process.
		// The variables left, right, mid is used to indicate the search range as well as the end index of the current test prefix.
		int left = 0;
		int right = shortest_string.length() - 1;
		int mid;
		string prefix;
        bool is_common_prefix;

		// Binary Search
		while(left <= right) {
			mid = (left + right) / 2;
			prefix = shortest_string.substr(0, mid + 1);
			is_common_prefix = true;

			// Check if the current prefix is a common prefix by examining every string of the array.
            for (size_t i = 0; i < strs.size(); i++)
            {
                if (strs[i].substr(0, mid + 1) != prefix)
                {
                    is_common_prefix = false;
                    break;
                }
            }

			// Continue the search process in the second half of the previous range.
			if (is_common_prefix)
				left = mid + 1;
			// Continue the search process in the first half of the previous range.
			else
				right = mid - 1;
		}

		// The end index of the longest common prefix is (left - 1), and left could be 0 indicating that the result is an empty string.
        return shortest_string.substr(0, left);
    }
};


int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    Solution solution;
    string longest_common_prefix = solution.longestCommonPrefix(strs);
    
    cout << longest_common_prefix << endl;

    return 0;
}

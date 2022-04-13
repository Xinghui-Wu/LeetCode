/**
 * 763. Partition Labels
 * 
 * You are given a string s.
 * We want to partition the string into as many parts as possible so that each letter appears in at most one part.
 * Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
 * Return a list of integers representing the size of these parts.
 * 
 * Constraints:
 *   1 <= s.length <= 500
 *   s consists of lowercase English letters.
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, Two Pointers, String, Greedy
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> part_sizes;

        // Record the first and last occurrences of each character.
        vector<vector<int>> occurrences(26, vector<int>(2, -1));

        for (int i = 0; i < s.size(); i++)
        {
            if (occurrences[s[i] - 'a'][0] == -1)
            {
                occurrences[s[i] - 'a'][0] = i;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (occurrences[s[i] - 'a'][1] == -1)
            {
                occurrences[s[i] - 'a'][1] = i;
            }
        }

        int interval[2] = {occurrences[s[0] - 'a'][0], occurrences[s[0] - 'a'][1]};
        int left;
        int right;

        for (int i = 1; i < s.size(); i++)
        {
            left = occurrences[s[i] - 'a'][0];
            right = occurrences[s[i] - 'a'][1];

            if (left < interval[1])
            {
                interval[1] = max(interval[1], right);
            }
            else
            {
                part_sizes.push_back(interval[1] - interval[0] + 1);

                interval[0] = left;
                interval[1] = right;
            }
        }

        part_sizes.push_back(interval[1] - interval[0] + 1);

        return part_sizes;
    }
};


int main()
{
    string s = "ababcbacadefegdehijhklij";

    Solution solution;
    vector<int> part_sizes = solution.partitionLabels(s);

    for (size_t i = 0; i < part_sizes.size(); i++)
    {
        cout << part_sizes[i] << endl;
    }
    
    return 0;
}

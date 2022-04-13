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

        // Record the last occurrences of each character.
        int last_indices[26];
        
        for (int i = 0; i < s.size(); i++)
        {
            last_indices[s[i] - 'a'] = i;
        }

        int start_index = 0;
        int end_index = 0;

        for (int i = 0; i < s.size(); i++)
        {
            end_index = max(end_index, last_indices[s[i] - 'a']);

            if (i == end_index)
            {
                part_sizes.push_back(end_index - start_index + 1);
                start_index = end_index + 1;
            }
        }

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

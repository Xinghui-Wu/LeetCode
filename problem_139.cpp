/**
 * 139. Word Break
 * 
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 * 
 * Constraints:
 *   1 <= s.length <= 300
 *   1 <= wordDict.length <= 1000
 *   1 <= wordDict[i].length <= 20
 *   s and wordDict[i] consist of only lowercase English letters.
 *   All the strings of wordDict are unique.
 * 
 * Difficulty: Medium
 * Related Topics: Hash Table, String, Dynamic Programming, Trie, Memoization
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int j = 1; j < dp.size(); j++)
        {
            for (string& word: wordDict)
            {
                if (j >= word.size())
                {
                    dp[j] = dp[j] || (dp[j - word.size()] && s.substr(j - word.size(), word.size()) == word);
                }
            }
        }
        
        return dp[s.size()];
    }
};


int main()
{
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    Solution solution;
    bool is_segmented = solution.wordBreak(s, wordDict);

    cout << is_segmented << endl;

    return 0;
}

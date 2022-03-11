/**
 * 72. Edit Distance
 * 
 * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * You have the following three operations permitted on a word:
 *   Insert a character
 *   Delete a character
 *   Replace a character
 * 
 * Constraints:
 *   0 <= word1.length, word2.length <= 500
 *   word1 and word2 consist of lowercase English letters.
 * 
 * Difficulty: Hard
 * Related Topics: String, Dynamic Programming
 */
#include <iostream>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        int dp[m + 1][n + 1];

        for (size_t i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (size_t j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        for (size_t i = 1; i <= m; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // Replace the words1[i - 1] with words2[j - 1], insert/delete words1[i - 1] or word2[j - 1]
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};


int main()
{
    string word1 = "intention";
    string word2 = "execution";

    Solution solution;
    int num_steps = solution.minDistance(word1, word2);

    cout << num_steps << endl;

    return 0;
}

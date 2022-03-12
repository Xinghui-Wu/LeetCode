/**
 * 455. Assign Cookies
 * 
 * Assume you are an awesome parent and want to give your children some cookies.
 * But, you should give each child at most one cookie.
 * Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j].
 * If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
 * Your goal is to maximize the number of your content children and output the maximum number.
 * 
 * Constraints:
 *   1 <= g.length <= 3 * 10^4
 *   0 <= s.length <= 3 * 10^4
 *   1 <= g[i], s[j] <= 2^31 - 1
 * 
 * Difficulty: Easy
 * Related Topics: Array, Greedy, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (s.empty())
        {
            return 0;
        }

        int num_children = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] >= g[num_children])
            {
                num_children++;
            }

            if (num_children == g.size())
            {
                return num_children;
            }
        }

        return num_children;
    }
};


int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    Solution solution;
    int num_children = solution.findContentChildren(g, s);

    cout << num_children << endl;

    return 0;
}

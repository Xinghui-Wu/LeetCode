/**
 * 435. Non-overlapping Intervals
 * 
 * Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 * 
 * Constraints:
 *   1 <= intervals.length <= 10^5
 *   intervals[i].length == 2
 *   -5 * 10^4 <= starti < endi <= 5 * 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Greedy, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int num_intervals = 1;

        // Sort the intervals based on the right bounds.
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) { return u[1] < v[1]; });

        int right = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (right <= intervals[i][0])
            {
                right = intervals[i][1];
                num_intervals++;
            }
        }

        return intervals.size() - num_intervals;
    }
};


int main()
{
    vector<vector<int>> intervals = {{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};

    Solution solution;
    int num_intervals = solution.eraseOverlapIntervals(intervals);

    cout << num_intervals << endl;

    return 0;
}

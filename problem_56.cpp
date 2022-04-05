/**
 * 56. Merge Intervals
 * 
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 * Constraints:
 *   1 <= intervals.length <= 10^4
 *   intervals[i].length == 2
 *   0 <= starti <= endi <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> merged_intervals;

        // Sort the intervals based on the starti.
        sort(intervals.begin(), intervals.end());

        // Set a baseline interval.
        vector<int> interval = intervals[0];

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (interval[1] < intervals[i][0])
            {
                merged_intervals.push_back(interval);
                interval = intervals[i];
            }
            else
            {
                interval[1] = max(interval[1], intervals[i][1]);
            }
        }

        merged_intervals.push_back(interval);

        return merged_intervals;
    }
};


int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    Solution solution;
    vector<vector<int>> merged_intervals = solution.merge(intervals);

    for (size_t i = 0; i < merged_intervals.size(); i++)
    {
        cout << merged_intervals[i][0] << ", " << merged_intervals[i][1] << endl;
    }
    
    return 0;
}

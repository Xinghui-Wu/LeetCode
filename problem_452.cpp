/**
 * 452. Minimum Number of Arrows to Burst Balloons
 * 
 * There are some spherical balloons taped onto a flat wall that represents the XY-plane.
 * The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend.
 * You do not know the exact y-coordinates of the balloons.
 * Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis.
 * A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend.
 * There is no limit to the number of arrows that can be shot.
 * A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 * Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 * 
 * Constraints:
 *   1 <= points.length <= 10^5
 *   points[i].length == 2
 *   -2^31 <= xstart < xend <= 2^31 - 1
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
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int num_arrows = 1;

        sort(points.begin(), points.end());

        // The right bound of the intersection.
        int x = points[0][1];

        for (auto& point: points)
        {
            if (x < point[0])
            {
                num_arrows++;
                x = point[1];
            }
            else
            {
                x = min(x, point[1]);
            }
        }

        return num_arrows;
    }
};


int main()
{
    vector<vector<int>> points = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};

    Solution solution;
    int num_arrows = solution.findMinArrowShots(points);

    cout << num_arrows << endl;

    return 0;
}

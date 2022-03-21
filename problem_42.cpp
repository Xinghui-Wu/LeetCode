/**
 * 42. Trapping Rain Water
 * 
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 * 
 * Constraints:
 *   n == height.length
 *   1 <= n <= 2 * 10^4
 *   0 <= height[i] <= 10^5
 * 
 * Difficulty: Hard
 * Related Topics: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int trap(vector<int>& height)
    {
        int water = 0;

        int left = 0;
        int right = height.size() - 1;
        
        int left_max = 0;
        int right_max = 0;

        while (left < right)
        {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if (height[left] < height[right])
            {
                water += left_max - height[left];
                left++;
            }
            else
            {
                water += right_max - height[right];
                right--;
            }
        }

        return water;
    }
};


int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution solution;
    int water = solution.trap(height);

    cout << water << endl;

    return 0;
}

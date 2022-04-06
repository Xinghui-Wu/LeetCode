/**
 * 45. Jump Game II
 * 
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   0 <= nums[i] <= 1000
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming, Greedy
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int num_jumps = 0;

        int n = nums.size();

        // Save the farest location that can be reached by this or next step.
        int largest_index = 0;
        // Save the farest location that can be reached by this step.
        int ending_index = 0;

        for (int i = 0; i < n - 1 && ending_index < n - 1; i++)
        {
            largest_index = max(largest_index, i + nums[i]);

            if (i == ending_index)
            {
                ending_index = largest_index;
                num_jumps++;
            }
        }
        
        return num_jumps;
    }
};


int main()
{
    vector<int> nums = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};

    Solution solution;
    int num_jumps = solution.jump(nums);

    cout << num_jumps << endl;
    
    return 0;
}

/**
 * 55. Jump Game
 * 
 * You are given an integer array nums.
 * You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   0 <= nums[i] <= 10^5
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
    bool canJump(vector<int>& nums)
    {
        // Save the farest location that can be reached.
        int largest_index = nums[0];
        int n = nums.size();

        for (int i = 0; i <= largest_index; i++)
        {
            largest_index = max(largest_index, i + nums[i]);

            if (largest_index >= n - 1)
            {
                return true;
            }
        }
        
        return false;
    }
};


int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution solution;
    bool is_feasible = solution.canJump(nums);

    cout << is_feasible << endl;

    return 0;
}

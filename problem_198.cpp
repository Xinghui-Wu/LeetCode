/**
 * 198. House Robber
 * 
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Constraints:
 *   1 <= nums.length <= 100
 *   0 <= nums[i] <= 400
 * 
 * Difficulty: Medium
 * Related Topics: Array, Dynamic Programming
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        int money;
        int money1 = nums[0];
        int money2 = nums[1];

        for (size_t i = 2; i < nums.size(); i++)
        {
            money = max(money1 + nums[i], money2);

            money1 = max(money1, money2);
            money2 = money;
        }
        
        return money;
    }
};


int main()
{
    vector<int> nums = {2, 1, 1, 2};

    Solution solution;
    int money = solution.rob(nums);

    cout << money << endl;

    return money;
}

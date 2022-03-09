/**
 * 213. House Robber II
 * 
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed.
 * All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Constraints:
 *   1 <= nums.length <= 100
 *   0 <= nums[i] <= 1000
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
        
        return max(rob_link_house(nums, 0, nums.size() - 2), rob_link_house(nums, 1, nums.size() - 1));
    }


    int rob_link_house(vector<int>& nums, int left, int right)
    {
        if (right - left == 1)
        {
            return max(nums[left], nums[right]);
        }
        
        int money;
        int money1 = nums[left];
        int money2 = nums[left + 1];

        for (size_t i = left + 2; i <= right; i++)
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
    vector<int> nums = {1, 2, 3, 1};

    Solution solution;
    int money = solution.rob(nums);

    cout << money << endl;

    return 0;
}

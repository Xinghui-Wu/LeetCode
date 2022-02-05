/**
 * 287. Find the Duplicate Number
 * 
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and uses only constant extra space.
 * 
 * Constraints:
 *   1 <= n <= 10^5
 *   nums.length == n + 1
 *   1 <= nums[i] <= n
 *   All the integers in nums appear only once except for precisely one integer which appears two or more times.
 * 
 * Follow up:
 *   How can we prove that at least one duplicate number must exist in nums?
 *   Can you solve the problem in linear runtime complexity?
 * 
 * Difficulty: Medium
 * Related Topics: Array, Two Pointers, Binary Search, Bit Manipulation
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        // Floyd's Tortoise and Hare (Cycle Detection)
        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = 0;

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution solution;
    int duplicate = solution.findDuplicate(nums);

    cout << duplicate << endl;

    return 0;
}

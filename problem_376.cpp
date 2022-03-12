/**
 * 376. Wiggle Subsequence
 * 
 * A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative.
 * The first difference (if one exists) may be either positive or negative.
 * A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
 * For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
 * In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
 * A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
 * Given an integer array nums, return the length of the longest wiggle subsequence of nums.
 * 
 * Constraints:
 *   1 <= nums.length <= 1000
 *   0 <= nums[i] <= 1000
 * 
 * Follow up:
 *   Could you solve this in O(n) time?
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
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        int previous_difference = nums[1] - nums[0];
        int difference;

        // Count the number of extreme points in the array.
        int wiggle_length = previous_difference != 0 ? 2 : 1;

        for (size_t i = 2; i < nums.size(); i++)
        {
            difference = nums[i] - nums[i - 1];

            if (difference > 0 && previous_difference <= 0 || difference < 0 && previous_difference >= 0)
            {
                previous_difference = difference;
                wiggle_length++;
            }
        }

        return wiggle_length;
    }
};


int main()
{
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    Solution solution;
    int wiggle_length = solution.wiggleMaxLength(nums);

    cout << wiggle_length << endl;

    return 0;
}

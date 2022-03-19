/**
 * 137. Single Number II
 * 
 * Given an integer array nums where every element appears three times except for one, which appears exactly once.
 * Find the single element and return it.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 * 
 * Constraints:
 *   1 <= nums.length <= 3 * 10^4
 *   -2^31 <= nums[i] <= 2^31 - 1
 *   Each element in nums appears exactly three times except for one element which appears once.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Bit Manipulation
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int single_number = 0;

        int sum;

        for (int i = 0; i < 32; i++)
        {
            sum = 0;

            for (int num: nums)
            {
                sum += (num >> i) & 1;
            }
            
            if (sum % 3 == 1)
            {
                single_number |= 1 << i;
            }
        }

        return single_number;
    }
};


int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    Solution solution;
    int single_number = solution.singleNumber(nums);

    cout << single_number << endl;

    return 0;
}

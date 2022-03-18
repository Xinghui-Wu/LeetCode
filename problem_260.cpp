/**
 * 260. Single Number III
 * 
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
 * Find the two elements that appear only once.
 * You can return the answer in any order.
 * You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
 * 
 * Constraints:
 *   2 <= nums.length <= 3 * 10^4
 *   -2^31 <= nums[i] <= 2^31 - 1
 *   Each integer in nums will appear twice, only two integers will appear once.
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
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> single_numbers(2);

        int xor_sum = 0;

        for (int num: nums)
        {
            xor_sum ^= num;
        }
        
        int mask = (xor_sum == INT32_MIN ? xor_sum : xor_sum & -xor_sum);
        
        for (int num: nums)
        {
            if (num & mask)
            {
                single_numbers[0] ^= num;
            }
            else
            {
                single_numbers[1] ^= num;
            }
        }

        return single_numbers;
    }
};


int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    Solution solution;
    vector<int> single_numbers = solution.singleNumber(nums);

    cout << single_numbers[0] << '\t' << single_numbers[1] << endl;

    return 0;
}

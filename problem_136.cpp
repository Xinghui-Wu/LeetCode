/**
 * 136. Single Number
 * 
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 * 
 * Constraints:
 *   1 <= nums.length <= 3 * 10^4
 *   -3 * 10^4 <= nums[i] <= 3 * 10^4
 *   Each element in the array appears twice except for one element which appears only once.
 * 
 * Difficulty: Easy
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
        int single_number = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++)
        {
            single_number ^= nums[i];
        }
        
        return single_number;
    }
};


int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution solution;
    int single_number = solution.singleNumber(nums);

    cout << single_number << endl;

    return 0;
}

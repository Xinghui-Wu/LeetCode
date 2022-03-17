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
#include <unordered_map>

using namespace std;


class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> single_numbers;

        unordered_map<int, int> count_map;

        for (int num: nums)
        {
            count_map[num]++;
        }

        for (auto& count: count_map)
        {
            if (count.second == 1)
            {
                single_numbers.push_back(count.first);
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

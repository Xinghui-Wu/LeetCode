/**
 * 41. First Missing Positive
 * 
 * Given an unsorted integer array nums, return the smallest missing positive integer.
 * You must implement an algorithm that runs in O(n) time and uses constant extra space.
 * 
 * Constraints:
 *   1 <= nums.length <= 5 * 10^5
 *   -2^31 <= nums[i] <= 2^31 - 1
 * 
 * Difficulty: Hard
 * Related Topics: Array, Hash Table
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();

        // Make all the negative values and zero positive.
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }

        int num;
        
        // Mark the element.
        for (size_t i = 0; i < n; i++)
        {
            num = abs(nums[i]);

            if (num <= n)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        // Find the missing positive.
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};


int main()
{
    vector<int> nums = {1, 2, 0};

    Solution solution;
    int missing_positive = solution.firstMissingPositive(nums);

    cout << missing_positive << endl;

    return 0;
}

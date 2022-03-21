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
        int missing_positive = 1;

        for (; missing_positive <= INT32_MAX; missing_positive++)
        {
            int i = 0;

            while (i < nums.size() && nums[i] != missing_positive)
            {
                i++;
            }
            
            if (i == nums.size())
            {
                return missing_positive;
            }
        }

        return missing_positive;
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

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
#include <unordered_set>

using namespace std;


class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int missing_positive = 1;

        unordered_set<int> num_set;

        for (int num: nums)
        {
            num_set.insert(num);
        }

        for (; missing_positive <= INT32_MAX; missing_positive++)
        {
            if (num_set.count(missing_positive) == 0)
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

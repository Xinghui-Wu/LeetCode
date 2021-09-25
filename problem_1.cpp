/**
 * 1. Two Sum
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 * Constraints:
 *   2 <= nums.length <= 10^4
 *   -10^9 <= nums[i] <= 10^9
 *   -10^9 <= target <= 10^9
 *   Only one valid answer exists.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Hash Table
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> indices;
        unordered_map<int, size_t> hashmap;

        // One-pass hash table.
        for (size_t i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (hashmap.count(complement))
            {
                indices.push_back(hashmap[complement]);
                indices.push_back(i);

                return indices;
            }

            hashmap.insert({nums[i], i});
        }

        return indices;
    }
};


int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> indices = solution.twoSum(nums, target);
    
    cout << indices[0] << ", " << indices[1] << endl;

    return 0;
}

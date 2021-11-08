/**
 * 169. Majority Element
 * 
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * Constraints:
 *   n == nums.length
 *   1 <= n <= 5 * 10^4
 *   -2^31 <= nums[i] <= 2^31 - 1
 * 
 * Follow-up:
 *   Could you solve the problem in linear time and in O(1) space?
 * 
 * Difficulty: Easy
 * Related Topics: Array, Hash Table, Divide and Conquer, Sorting, Counting
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int majority_element = nums[0];
        int count = 1;

        // Boyer-Moore Voting Algorithm
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (count == 0)
            {
                majority_element = nums[i];
                count = 1;
            }
            else if (nums[i] == majority_element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        
        return majority_element;
    }
};


int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution solution;
    int majority_element = solution.majorityElement(nums);

    cout << majority_element << endl;

    return 0;
}

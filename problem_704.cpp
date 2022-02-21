/**
 * 704. Binary Search
 * 
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
 * If target exists, then return its index. Otherwise, return -1.
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 < nums[i], target < 10^4
 *   All the integers in nums are unique.
 *   nums is sorted in ascending order.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Binary Search
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while (left <= right)
        {
            mid = (left + right) / 2;
            
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        
        return -1;
    }
};


int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    Solution solution;
    int index = solution.search(nums, target);

    cout << index << endl;

    return 0;
}

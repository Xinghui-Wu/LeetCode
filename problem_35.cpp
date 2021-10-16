/**
 * 35. Search Insert Position
 * 
 * Given a sorted array of distinct integers and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 *   nums contains distinct values sorted in ascending order.
 *   -10^4 <= target <= 10^4
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
    int searchInsert(vector<int>& nums, int target)
    {
		int left = 0;
		int right = nums.size() - 1;
		int mid;

        // Binary Search
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
		
		// If the target is not found, return the index where it would be if it were inserted in order.
		if (nums[mid] < target)
        {
			return mid + 1;
        }
		else
        {
			return mid;
        }
        
        return 0;
    }
};


int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    Solution solution;
    int index = solution.searchInsert(nums, target);

    cout << index << endl;

    return 0;
}

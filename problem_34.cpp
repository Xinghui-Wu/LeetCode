/**
 * 34. Find First and Last Position of Element in Sorted Array
 * 
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Constraints:
 *   0 <= nums.length <= 10^5
 *   -10^9 <= nums[i] <= 10^9
 *   nums is a non-decreasing array.
 *   -10^9 <= target <= 10^9
 * 
 * Difficulty: Medium
 * Related Topics: Array, Binary Search
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> range = {-1, -1};

        int index = binary_search(nums, target, 0, nums.size() - 1);

        if (index != -1)
        {
            int starting = index;
            int ending = index;

            while (starting != -1)
            {
                range[0] = starting;
                starting = binary_search(nums, target, 0, starting - 1);
            }

            while (ending != -1)
            {
                range[1] = ending;
                ending = binary_search(nums, target, ending + 1, nums.size() - 1);
            }
        }
        
        return range;
    }


    /**
     * Find the element with the target value in a sorted array using binary search.
     */
    int binary_search(vector<int>& nums, int target, int left, int right)
    {
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
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution solution;
    vector<int> range = solution.searchRange(nums, target);

    cout << range[0] << ", " << range[1] << endl;

    return 0;
}

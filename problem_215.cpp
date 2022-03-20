/**
 * 215. Kth Largest Element in an Array
 * 
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Constraints:
 *   1 <= k <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 * 
 * Difficulty: Medium
 * Related Topics: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int length = nums.size();

        // Adjust from the last non-leaf node.
        for (int i = length / 2 - 1; i >= 0; i--)
        {
            build_heap(nums, i, length - 1);
        }
        
        // Swap the first and the i-th value to make the last portion of array sorted.
        for (int i = length - 1; i >= length - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            build_heap(nums, 0, i - 1);
        }

        return nums[0];
    }


    void build_heap(vector<int>& nums, int start, int end)
    {
        int parent = start;
        int child = 2 * parent + 1;

        while (child <= end)
        {
            // Choose the larger child.
            if (child + 1 <= end && nums[child] < nums[child + 1])
            {
                child++;
            }
            
            // Compare the parent and the child.
            if (nums[parent] > nums[child])
            {
                break;
            }
            else
            {
                swap(nums[parent], nums[child]);
                parent = child;
                child = 2 * parent + 1;
            }
        }
    }
};


int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    Solution solution;
    int kth_largest = solution.findKthLargest(nums, k);

    cout << kth_largest << endl;

    return 0;
}

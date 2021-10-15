/**
 * 26. Remove Duplicates from Sorted Array
 * 
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums.
 * More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
 * It does not matter what you leave beyond the first k elements.
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * Constraints:
 *   0 <= nums.length <= 3 * 10^4
 *   -100 <= nums[i] <= 100
 *   nums is sorted in non-decreasing order.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Two Pointers
 */ 
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        // Handle the exceptional case.
        if (nums.empty())
        {
            return 0;
        }

        // Maintain the current index k, while k + 1 is the total length.
        int k = 0;

        // Compare each element in the vector with the current one indexed by k.
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[k])
            {
                k++;
                nums[k] = nums[i];
            }
        }

        return k + 1;
    }
};


int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution solution;
    int k = solution.removeDuplicates(nums);

    cout << k << endl << endl;

    for (size_t i = 0; i < k; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}

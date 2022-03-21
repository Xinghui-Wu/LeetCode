/**
 * 31. Next Permutation
 * 
 * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 * For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
 * The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
 * More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container.
 * If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
 * Given an array of integers nums, find the next permutation of nums.
 * The replacement must be in place and use only constant extra memory.
 * 
 * Constraints:
 *   1 <= nums.length <= 100
 *   0 <= nums[i] <= 100
 * 
 * Difficulty: Medium
 * Related Topics: Array, Two Pointers
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = nums.size() - 2;

        // Find the first pair from the end that nums[i] < nums[i + 1].
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        
        if (i >= 0)
        {
            int j = nums.size() - 1;

            // Find the first pair from the end that nums[i] < nums[j].
            while (j >= 0 && nums[i] >= nums[j])
            {
                j--;
            }
            
            swap(nums[i], nums[j]);
        }
        
        reverse(nums.begin() + i + 1, nums.end());
    }
};


int main()
{
    vector<int> nums = {1, 2, 3};

    Solution solution;
    solution.nextPermutation(nums);

    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    
    return 0;
}

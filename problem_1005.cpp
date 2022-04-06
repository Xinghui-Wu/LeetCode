/**
 * 1005. Maximize Sum Of Array After K Negations
 * 
 * Given an integer array nums and an integer k, modify the array in the following way: choose an index i and replace nums[i] with -nums[i].
 * You should apply this process exactly k times.
 * You may choose the same index i multiple times.
 * Return the largest possible sum of the array after modifying it in this way.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -100 <= nums[i] <= 100
 *   1 <= k <= 10^4
 * 
 * Difficulty: Easy
 * Related Topics: Array, Greedy, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        // Sort the array according to the abs value.
        sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) > abs(b); });

        // Modify the smaller negatives at first.
        for (int i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        
        // Modify the smallest non-negative if needed.
        if (k % 2 == 1)
        {
            nums[nums.size() - 1] *= -1;
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};


int main()
{
    vector<int> nums = {2, -3, -1, 5, -4};
    int k = 2;

    Solution solution;
    int largest_sum = solution.largestSumAfterKNegations(nums, k);

    cout << largest_sum << endl;

    return 0;
}

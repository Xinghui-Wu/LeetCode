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
#include <queue>

using namespace std;


class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        int largest_sum = 0;

        priority_queue<int, vector<int>, greater<int>> queue(nums.begin(), nums.end());
        int min_value;

        // Each time modify the minimal of the current array.
        for (int i = 0; i < k; i++)
        {
            min_value = queue.top();
            queue.pop();
            queue.push(-min_value);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            largest_sum += queue.top();
            queue.pop();
        }

        return largest_sum;
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

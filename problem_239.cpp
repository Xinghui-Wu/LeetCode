/**
 * 239. Sliding Window Maximum
 * 
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 * You can only see the k numbers in the window.
 * Each time the sliding window moves right by one position.
 * Return the max sliding window.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   -10^4 <= nums[i] <= 10^4
 *   1 <= k <= nums.length
 * 
 * Difficulty: Hard
 * Related Topics: Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> max_window_nums(nums.size() - k + 1);

        // Use a monotonic queue to save the indices that are still in the window range.
        // The numbers corresponding to the indices in the queue should be monotonically decreasing.
        deque<int> monotonic_queue;

        for (int i = 0; i < k - 1; i++)
        {
            while (!monotonic_queue.empty() && nums[i] >= nums[monotonic_queue.back()])
            {
                monotonic_queue.pop_back();
            }
            
            monotonic_queue.push_back(i);
        }

        for (int i = k - 1; i < nums.size(); i++)
        {
            while (!monotonic_queue.empty() && nums[i] >= nums[monotonic_queue.back()])
            {
                monotonic_queue.pop_back();
            }
            
            monotonic_queue.push_back(i);

            if (monotonic_queue.front() <= i - k)
            {
                monotonic_queue.pop_front();
            }
            
            max_window_nums[i - k + 1] = nums[monotonic_queue.front()];
        }

        return max_window_nums;
    }
};


int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution solution;
    vector<int> max_window_nums = solution.maxSlidingWindow(nums, k);

    for (size_t i = 0; i < max_window_nums.size(); i++)
    {
        cout << max_window_nums[i] << endl;
    }
    
    return 0;
}

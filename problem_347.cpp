/**
 * 347. Top K Frequent Elements
 * 
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   k is in the range [1, the number of unique elements in the array].
 *   It is guaranteed that the answer is unique.
 * 
 * Follow up:
 *   Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> top_k_frequent_nums(k);

        // Count the occurrences of each number in the vector.
        unordered_map<int, int> count_map;

        for (size_t i = 0; i < nums.size(); i++)
        {
            count_map[nums[i]]++;
        }

        // Use priority queue (min heap) to sort the top k frequent numbers.
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> frequency_queue(cmp);
        
        for (auto& count: count_map)
        {
            if (frequency_queue.size() < k)
            {
                frequency_queue.emplace(count.first, count.second);
            }
            else if (frequency_queue.top().second < count.second)
            {
                frequency_queue.pop();
                frequency_queue.emplace(count.first, count.second);
            }
        }

        for (int i = k - 1; i >= 0; i--)
        {
            top_k_frequent_nums[i] = frequency_queue.top().first;
            frequency_queue.pop();
        }
        
        return top_k_frequent_nums;
    }


    static bool cmp(pair<int, int>& m, pair<int, int>& n)
    {
        return m.second > n.second;
    }
};


int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution solution;
    vector<int> top_k_frequent_nums = solution.topKFrequent(nums, k);

    for (size_t i = 0; i < k; i++)
    {
        cout << top_k_frequent_nums[i] << endl;
    }
    
    return 0;
}

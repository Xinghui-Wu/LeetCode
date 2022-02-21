/**
 * 349. Intersection of Two Arrays
 * 
 * Given two integer arrays nums1 and nums2, return an array of their intersection.
 * Each element in the result must be unique and you may return the result in any order.
 * 
 * Constraints:
 *   1 <= nums1.length, nums2.length <= 1000
 *   0 <= nums1[i], nums2[i] <= 1000
 * 
 * Difficulty: Easy
 * Related Topics: Array, Hash Table, Two Pointers, Binary Search, Sorting
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return intersection(nums2, nums1);
        }

        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        unordered_set<int> intersection_set;
        
        for (size_t i = 0; i < nums2.size(); i++)
        {
            if (nums_set.count(nums2[i]) > 0)
            {
                intersection_set.insert(nums2[i]);
            }
        }

        vector<int> nums_intersection(intersection_set.begin(), intersection_set.end());

        return nums_intersection;
    }
};


int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    Solution solution;
    vector<int> nums_intersection = solution.intersection(nums1, nums2);

    for (size_t i = 0; i < nums_intersection.size(); i++)
    {
        cout << nums_intersection[i] << endl;
    }
    
    return 0;
}

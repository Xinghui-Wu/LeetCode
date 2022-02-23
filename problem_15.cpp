/**
 * 15. 3Sum
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Constraints:
 *   0 <= nums.length <= 3000
 *   -10^5 <= nums[i] <= 10^5
 * 
 * Difficulty: Medium
 * Related Topics: Array, Two Pointers, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> triplets;

        if (nums.size() < 3)
        {
            return triplets;
        }

        // Sort the vector so that nums[i] <= nums[j] <= nums[k] is guaranteed to avoid duplicate triplets.
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            // Skip this iteration to avoid duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
            {
                break;
            }
            if (nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1] < 0)
            {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else
                {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip the iterations to avoid duplicate triplets.
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }

        return triplets;
    }
};


int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution solution;
    vector<vector<int>> triplets = solution.threeSum(nums);

    for (size_t i = 0; i < triplets.size(); i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << triplets[i][j] << "\t";
        }
        
        cout << endl;
    }
    
    return 0;
}

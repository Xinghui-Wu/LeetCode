/**
 * 18. 4Sum
 * 
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *   0 <= a, b, c, d < n
 *   a, b, c, and d are distinct.
 *   nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 * 
 * Constraints:
 *   1 <= nums.length <= 200
 *   -10^9 <= nums[i] <= 10^9
 *   -10^9 <= target <= 10^9
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
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> quadruplets;

        if (nums.size() < 4)
        {
            return quadruplets;
        }
        
        // Sort the vector so that nums[a] <= nums[b] <= nums[c] <= nums[d] is guaranteed to avoid duplicate quadruplets.
        sort(nums.begin(), nums.end());

        for (int a = 0; a < nums.size() - 3; a++)
        {
            // Skip this iteration to avoid duplicate quadruplets.
            if (a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }

            if ((long) nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target)
            {
                break;
            }
            if ((long) nums[a] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
            {
                continue;
            }
            
            for (int b = a + 1; b < nums.size() - 2; b++)
            {
                // Skip this iteration to avoid duplicate quadruplets.
                if (b > a + 1 && nums[b] == nums[b - 1])
                {
                    continue;
                }

                if ((long) nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target)
                {
                    break;
                }
                if ((long) nums[a] + nums[b] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
                {
                    continue;
                }

                int c = b + 1;
                int d = nums.size() - 1;

                while (c < d)
                {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];

                    if (sum < target)
                    {
                        c++;
                    }
                    else if (sum > target)
                    {
                        d--;
                    }
                    else
                    {
                        quadruplets.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;

                        // Skip the iterations to avoid duplicate quadruplets.
                        while (c < d && nums[c] == nums[c - 1])
                        {
                            c++;
                        }
                        while (c < d && nums[d] == nums[d + 1])
                        {
                            d--;
                        }
                    }
                }
            }
        }

        return quadruplets;
    }
};


int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution solution;
    vector<vector<int>> quadruplets = solution.fourSum(nums, target);

    for (size_t i = 0; i < quadruplets.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << quadruplets[i][j] << "\t";
        }
        
        cout << endl;
    }

    return 0;
}

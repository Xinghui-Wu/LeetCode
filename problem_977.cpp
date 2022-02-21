/**
 * 977. Squares of a Sorted Array
 * 
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 * 
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 <= nums[i] <= 10^4
 *   nums is sorted in non-decreasing order.
 * 
 * Follow up:
 *   Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
 * 
 * Difficulty: Easy
 * Related Topics: Array, Two Pointers, Sorting
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> squares(nums.size());

        // One of the elements at the two ends of nums can have the largest square.
        // Use two pointers to track the current two ends and another pointer to index the sorted squares vector.
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        while (k >= 0)
        {
            if (nums[i] * nums[i] >= nums[j] * nums[j])
            {
                squares[k--] = nums[i] * nums[i];
                i++;
            }
            else
            {
                squares[k--] = nums[j] * nums[j];
                j--;
            }
        }

        return squares;
    }
};


int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};

    Solution solution;
    vector<int> squares = solution.sortedSquares(nums);

    for (size_t i = 0; i < squares.size(); i++)
    {
        cout << squares[i] << endl;
    }
    
    return 0;
}

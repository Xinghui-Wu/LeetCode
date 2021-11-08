/**
 * 167. Two Sum II - Input Array Is Sorted
 * 
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
 * Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 * 
 * Constraints:
 *   2 <= numbers.length <= 3 * 10^4
 *   -1000 <= numbers[i] <= 1000
 *   numbers is sorted in non-decreasing order.
 *   -1000 <= target <= 1000
 *   The tests are generated such that there is exactly one solution.
 * 
 * Difficulty: Easy
 * Related Topics: Array, Two Pointers, Binary Search
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> indices(2);

        int i = 0;
        int j = numbers.size() - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else if (numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                indices[0] = i + 1;
                indices[1] = j + 1;

                return indices;
            }
        }

        return indices;
    }
};


int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> indices = solution.twoSum(numbers, target);

    cout << indices[0] << ", " << indices[1] << endl;

    return 0;
}

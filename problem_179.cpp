/**
 * 179. Largest Number
 * 
 * Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 * Since the result may be very large, so you need to return a string instead of an integer.
 * 
 * Constraints:
 *   1 <= nums.length <= 100
 *   0 <= nums[i] <= 10^9
 * 
 * Difficulty: Medium
 * Related Topics: String, Greedy, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
private:
    static bool cmp(string a, string b)
    {
        return (a + b) > (b + a);
    }

public:
    string largestNumber(vector<int>& nums)
    {
        string largest_number;
        
        vector<string> str_nums(nums.size());

        for (size_t i = 0; i < nums.size(); i++)
        {
            str_nums[i] = to_string(nums[i]);
        }

        sort(str_nums.begin(), str_nums.end(), cmp);

        if (str_nums[0] == "0")
        {
            return "0";
        }

        for (string s: str_nums)
        {
            largest_number.append(s);
        }

        return largest_number;
    }    
};


int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};

    Solution solution;
    string largest_number = solution.largestNumber(nums);

    cout << largest_number << endl;

    return 0;
}

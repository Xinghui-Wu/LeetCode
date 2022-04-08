/**
 * 406. Queue Reconstruction by Height
 * 
 * You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order).
 * Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
 * Reconstruct and return the queue that is represented by the input array people.
 * The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
 * 
 * Constraints:
 *   1 <= people.length <= 2000
 *   0 <= hi <= 10^6
 *   0 <= ki < people.length
 *   It is guaranteed that the queue can be reconstructed.
 * 
 * Difficulty: Medium
 * Related Topics: Array, Greedy, Sorting
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        int n = people.size();

        vector<vector<int>> queue(n);

        // Sort the people from the shortest to the tallest.
        // If two persons are of the same height, the one with larger k precedes the other one.
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) { return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]); });

        // Reserve some spaces from the i-th person.
        int num_spaces;

        for (const vector<int>& person: people)
        {
            num_spaces = person[1] + 1;

            for (int i = 0; i < n; i++)
            {
                if (queue[i].empty())
                {
                    num_spaces--;

                    if (num_spaces == 0)
                    {
                        queue[i] = person;
                        break;
                    }
                }
            }
        }
        
        return queue;
    }
};


int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

    Solution solution;
    vector<vector<int>> queue = solution.reconstructQueue(people);

    for (size_t i = 0; i < queue.size(); i++)
    {
        cout << queue[i][0] << '\t' << queue[i][1] << endl;
    }
    
    return 0;
}

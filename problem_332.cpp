/**
 * 332. Reconstruct Itinerary
 * 
 * You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight.
 * Reconstruct the itinerary in order and return it.
 * All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK".
 * If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
 * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 * You may assume all tickets form at least one valid itinerary.
 * You must use all the tickets once and only once.
 * 
 * Constraints:
 *   1 <= tickets.length <= 300
 *   tickets[i].length == 2
 *   fromi.length == 3
 *   toi.length == 3
 *   fromi and toi consist of uppercase English letters.
 *   fromi != toi
 * 
 * Difficulty: Hard
 * Related Topics: Depth-First Search, Graph, Eulerian Circuit
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        vector<string> itinerary(tickets.size() + 1);
        itinerary[0] = "JFK";

        // Save the pairs of the departure and arrival airports and mark their occurrence.
        unordered_map<string, map<string, int>> targets;

        for (size_t i = 0; i < tickets.size(); i++)
        {
            targets[tickets[i][0]][tickets[i][1]]++;
        }

        backtracking(itinerary, targets, 1);
        
        return itinerary;
    }


    bool backtracking(vector<string>& itinerary, unordered_map<string, map<string, int>>& targets, int index)
    {
        if (index == itinerary.size())
        {
            return true;
        }

        // The departure is the previously saved airport in the itinerary.
        // Iteratively deal with the possible arrival airports by lexical order.
        // If one solution is already found, terminate the whole searching process.
        for (pair<const string, int>& target: targets[itinerary[index - 1]])
        {
            if (target.second > 0)
            {
                itinerary[index] = target.first;
                target.second--;

                if (backtracking(itinerary, targets, index + 1))
                {
                    return true;
                }

                target.second++;
            }
        }

        return false;
    }
};


int main()
{
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    Solution solution;
    vector<string> itinerary = solution.findItinerary(tickets);

    for (size_t i = 0; i < itinerary.size(); i++)
    {
        cout << itinerary[i] << endl;
    }
    
    return 0;
}

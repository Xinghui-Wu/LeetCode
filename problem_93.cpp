/**
 * 93. Restore IP Addresses
 * 
 * A valid IP address consists of exactly four integers separated by single dots.
 * Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
 * Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
 * You are not allowed to reorder or remove any digits in s.
 * You may return the valid IP addresses in any order.
 * 
 * Constraints:
 *   1 <= s.length <= 20
 *   s consists of digits only.
 * 
 * Difficulty: Medium
 * Related Topics: String, Backtracking
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ip_addresses;

        if (s.size() < 4 || s.size() > 12)
        {
            return ip_addresses;
        }

        vector<string> path;

        backtracking(s, ip_addresses, path, 0);
        
        return ip_addresses;
    }


    void backtracking(string& s, vector<string>& ip_addresses, vector<string>& path, int index)
    {
        if (path.size() == 4)
        {
            ip_addresses.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);

            return;
        }
        
        string sub_str;

        for (int i = index + 1; i - index <= 3 && i <= s.size(); i++)
        {
            if (s.size() - i <= 3 * (3 - path.size()))
            {
                sub_str = s.substr(index, i - index);
                
                if (stoi(sub_str) <= 255 && (i - index == 1 || sub_str[0] != '0'))
                {
                    path.push_back(sub_str);
                    backtracking(s, ip_addresses, path, i);
                    path.pop_back();
                }
            }
        }
    }
};


int main()
{
    string s = "25525511135";

    Solution solution;
    vector<string> ip_addresses = solution.restoreIpAddresses(s);

    for (size_t i = 0; i < ip_addresses.size(); i++)
    {
        cout << ip_addresses[i] << endl;
    }
    
    return 0;
}

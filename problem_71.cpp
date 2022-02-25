/**
 * 71. Simplify Path
 * 
 * Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
 * In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.
 * For this problem, any other format of periods such as '...' are treated as file/directory names.
 * The canonical path should have the following format:
 *   The path starts with a single slash '/'.
 *   Any two directories are separated by a single slash '/'.
 *   The path does not end with a trailing '/'.
 *   The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
 * Return the simplified canonical path.
 * 
 * Constraints:
 *   1 <= path.length <= 3000
 *   path consists of English letters, digits, period '.', slash '/' or '_'.
 *   path is a valid absolute Unix path.
 * 
 * Difficulty: Medium
 * Related Topics: String, Stack
 */
#include <iostream>
#include <deque>

using namespace std;


class Solution
{
public:
    string simplifyPath(string path)
    {
        string simplified_path;

        deque<string> path_deque;
        path_deque.push_back("/");

        int length = path.size();

        for (int i = 1; i < length; i++)
        {
            if (path[i] == '/')
            {
                if (path[i - 1] != '/')
                {
                    path_deque.push_back("/");
                }
            }
            else if (path[i] != '.')
            {
                int j = i + 1;

                while (j < length && path[j] != '/')
                {
                    j++;
                }
                
                path_deque.push_back(path.substr(i, j - i));

                i = j - 1;
            }
            else if (i + 1 < length)
            {
                if (path[i + 1] == '/')
                {
                    i = i + 1;
                }
                else if (path[i + 1] == '.' && (i + 2 == length || path[i + 2] == '/'))
                {
                    if (path_deque.size() >= 3)
                    {
                        path_deque.pop_back();
                        path_deque.pop_back();
                    }
                    
                    i = i + 2;
                }
                else
                {
                    int j = i + 1;

                    while (j < length && path[j] != '/')
                    {
                        j++;
                    }
                
                    path_deque.push_back(path.substr(i, j - i));

                    i = j - 1;
                }
            }
        }
        
        while (!path_deque.empty())
        {
            simplified_path.append(path_deque.front());
            path_deque.pop_front();
        }

        if (simplified_path.size() > 1 && simplified_path.back() == '/')
        {
            simplified_path.pop_back();
        }
        
        return simplified_path;
    }
};


int main()
{
    string path = "/../";

    Solution solution;
    string simplified_path = solution.simplifyPath(path);

    cout << simplified_path << endl;

    return 0;
}

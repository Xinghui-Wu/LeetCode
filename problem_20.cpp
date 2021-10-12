/**
 * 20. Valid Parentheses
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *   Open brackets must be closed by the same type of brackets.
 *   Open brackets must be closed in the correct order.
 * 
 * Constraints:
 *   1 <= s.length <= 10^4
 *   s consists of parentheses only '()[]{}'.
 * 
 * Difficulty: Easy
 * Related Topics: String, Stack
 */
#include <iostream>
#include <stack>

using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        // The stack data structure can come in handy here in representing this recursive structure of the problem.
        stack<char> parenthesis_stack;
        
		// Traverse the input string character by character.
		// If the current character is one of the open brackets, push it onto the stack.
		// If the current character is one of the close brackets, pop a character from the stack (if the stack is not empty) and check whether it can make a pair with the current character.
		for (size_t i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            // Push an open bracket onto the stack.
            case '(':
                parenthesis_stack.push('(');
                break;
            case '[':
                parenthesis_stack.push('[');
                break;
            case '{':
                parenthesis_stack.push('{');
                break;
            // Pop a character from the stack if met with a close bracket.
            case ')':
                if (parenthesis_stack.empty() || parenthesis_stack.top() != '(')
                {
                    return false;
                }
                parenthesis_stack.pop();
				break;
            case ']':
                if (parenthesis_stack.empty() || parenthesis_stack.top() != '[')
                {
                    return false;
                }
                parenthesis_stack.pop();
				break;
            case '}':
                if (parenthesis_stack.empty() || parenthesis_stack.top() != '{')
                {
                    return false;
                }
                parenthesis_stack.pop();
				break;
            default:
                return false;
            }
        }
        
		// After traversing the input string and the corresponding push and pop operations, check the status of the bracket stack.
		// If the bracket stack is empty, return true.
		// Otherwise, return false.
		if (parenthesis_stack.empty())
        {
			return true;
        }
		else
        {
			return false;
        }
    }
};


int main()
{
    string s = "()[]{}";

    Solution solution;
    bool is_valid = solution.isValid(s);
    
    cout << is_valid << endl;

    return 0;
}

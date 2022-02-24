/**
 * 150. Evaluate Reverse Polish Notation
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, and /.
 * Each operand may be an integer or another expression.
 * Note that division between two integers should truncate toward zero.
 * It is guaranteed that the given RPN expression is always valid.
 * That means the expression would always evaluate to a result, and there will not be any division by zero operation.
 * 
 * Constraints:
 *   1 <= tokens.length <= 10^4
 *   tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
 * 
 * Difficulty: Medium
 * Related Topics: Array, Math, Stack
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> token_stack;
        int operand1;
        int operand2;

        for (string token: tokens)
        {
            if (token == "+")
            {
                operand1 = token_stack.top();
                token_stack.pop();
                operand2 = token_stack.top();
                token_stack.pop();

                token_stack.push(operand2 + operand1);
            }
            else if (token == "-")
            {
                operand1 = token_stack.top();
                token_stack.pop();
                operand2 = token_stack.top();
                token_stack.pop();

                token_stack.push(operand2 - operand1);
            }
            else if (token == "*")
            {
                operand1 = token_stack.top();
                token_stack.pop();
                operand2 = token_stack.top();
                token_stack.pop();

                token_stack.push(operand2 * operand1);
            }
            else if (token == "/")
            {
                operand1 = token_stack.top();
                token_stack.pop();
                operand2 = token_stack.top();
                token_stack.pop();

                token_stack.push(operand2 / operand1);
            }
            else
            {
                token_stack.push(stoi(token));
            }
        }

        return token_stack.top();
    }
};


int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    Solution solution;
    int result = solution.evalRPN(tokens);

    cout << result << endl;

    return 0;
}

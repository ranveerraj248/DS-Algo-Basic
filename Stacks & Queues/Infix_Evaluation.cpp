// 1. You are given an infix expression.
// 2. You are required to evaluate and print it's value.
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int precedence(char optor)
{
    if (optor == '+')
    {
        return 1;
    }
    else if (optor == '-')
    {
        return 1;
    }
    else if (optor == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}
int operation(int v1, int v2, char optor)
{
    if (optor == '+')
    {
        return v1 + v2;
    }
    else if (optor == '-')
    {
        return v1 - v2;
    }
    else if (optor == '*')
    {
        return v1 * v2;
    }
    else
    {
        return (int)(v1 / v2);
    }
}
int main()
{
    string str;
    getline(cin, str);
    stack<int> operands;
    stack<char> operators;
    for (char ch : str)
    {
        if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            while (operators.size() > 0 && operators.top() != '(' &&
                   precedence(ch) <= precedence(operators.top()))
            {
                char optor = operators.top();
                operators.pop();
                int v2 = operands.top();
                operands.pop();
                int v1 = operands.top();
                operands.pop();

                int opv = operation(v1, v2, optor);
                operands.push(opv);
            }
            operators.push(ch);
        }
        else if (isdigit(ch))
        {
            operands.push(ch - '0');
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (operators.top() != '(')
            {
                char optor = operators.top();
                operators.pop();
                int v2 = operands.top();
                operands.pop();
                int v1 = operands.top();
                operands.pop();

                int opv = operation(v1, v2, optor);
                operands.push(opv);
            }
            operators.pop();
        }
    }
    while (operators.size() != 0)
    {
        char optor = operators.top();
        operators.pop();
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();

        int opv = operation(v1, v2, optor);
        operands.push(opv);
    }
    cout << operands.top();
    return 0;
}
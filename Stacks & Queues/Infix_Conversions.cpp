// 1. You are given an infix expression.
// 2. You are required to convert it to postfix and print it.
// 3. You are required to convert it to prefix and print it.
// 1. Expression is balanced
// 2. The only operators used are +, -, *, /
// 3. Opening and closing brackets - () - are used to impact precedence of operations
// 4. + and - have equal precedence which is less than * and /. * and / also have equal precedence.
// 5. In two operators of equal precedence give preference to the one on left.
// 6. All operands are single digit numbers.
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
    else if (optor == '/')
    {
        return 2;
    }
    else
        return 0;
}

int main()
{
    string str;
    getline(cin, str);
    stack<string> prefix;
    stack<string> postfix;
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

                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = optor + prev1 + prev2;
                prefix.push(prev);

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + optor;
                postfix.push(postv);
            }
            operators.push(ch);
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string s;
            s += ch;
            postfix.push(s);
            prefix.push(s);
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

                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = optor + prev1 + prev2;
                prefix.push(prev);

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + optor;
                postfix.push(postv);
            }
            operators.pop();
        }
    }
    while (operators.size() != 0)
    {
        char optor = operators.top();
        operators.pop();

        string prev2 = prefix.top();
        prefix.pop();
        string prev1 = prefix.top();
        prefix.pop();
        string prev = optor + prev1 + prev2;
        prefix.push(prev);

        string postv2 = postfix.top();
        postfix.pop();
        string postv1 = postfix.top();
        postfix.pop();
        string postv = postv1 + postv2 + optor;
        postfix.push(postv);
    }
    cout << postfix.top() << endl;
    cout << prefix.top() << endl;
    return 0;
}
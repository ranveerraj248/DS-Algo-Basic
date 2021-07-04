// 1. You are given a postfix expression.
// 2. You are required to evaluate it and print it's value.
// 3. You are required to convert it to infix and print it.
// 4. You are required to convert it to prefix and print it.
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int operation(int val1, int val2, char optor)
{
    if (optor == '+')
    {
        return val1 + val2;
    }
    else if (optor == '-')
    {
        return val1 - val2;
    }
    else if (optor == '*')
    {
        return val1 * val2;
    }
    else
    {
        return val1 / val2;
    }
}
int main()
{
    string str;
    getline(cin, str);
    stack<int> value;
    stack<string> prefix;
    stack<string> infix;
    for (char ch : str)
    {
        if (isdigit(ch))
        {
            value.push(ch - '0');
            string pre = "";
            string in = "";
            pre += ch;
            in += ch;
            prefix.push(pre);
            infix.push(in);
        }
        else
        {
            int val2 = value.top();
            value.pop();
            int val1 = value.top();
            value.pop();
            value.push(operation(val1, val2, ch));

            string pre = "";
            string prev2 = prefix.top();
            prefix.pop();
            string prev1 = prefix.top();
            prefix.pop();

            pre = ch + prev1 + prev2;
            prefix.push(pre);

            string in = "";
            string inv2 = infix.top();
            infix.pop();
            string inv1 = infix.top();
            infix.pop();

            in = '(' + inv1 + ch + inv2 + ')';
            infix.push(in);
        }
    }
    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout << prefix.top() << endl;
    return 0;
}
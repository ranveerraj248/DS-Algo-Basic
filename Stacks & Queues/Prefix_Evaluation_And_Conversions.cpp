// 1. You are given a prefix expression.
// 2. You are required to evaluate it and print it's value.
// 3. You are required to convert it to infix and print it.
// 4. You are required to convert it to postfix and print it.
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
    stack<string> infix;
    stack<string> postfix;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if (isdigit(ch))
        {
            value.push(ch - '0');
            string post = "";
            string in = "";
            post += ch;
            in += ch;
            postfix.push(post);
            infix.push(in);
        }
        else
        {

            int val1 = value.top();
            value.pop();
            int val2 = value.top();
            value.pop();
            value.push(operation(val1, val2, ch));

            string in = "";
            string inv1 = infix.top();
            infix.pop();
            string inv2 = infix.top();
            infix.pop();

            in = '(' + inv1 + ch + inv2 + ')';
            infix.push(in);

            string post = "";
            string postv1 = postfix.top();
            postfix.pop();
            string postv2 = postfix.top();
            postfix.pop();

            post = postv1 + postv2 + ch;
            postfix.push(post);
        }
    }
    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout << postfix.top() << endl;
    return 0;
}
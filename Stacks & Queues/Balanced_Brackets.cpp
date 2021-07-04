// 1. You are given a string exp representing an expression.
// 2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

// e.g.
// [(a + b) + {(c + d) * (e / f)}] -> true
// [(a + b) + {(c + d) * (e / f)]} -> false
// [(a + b) + {(c + d) * (e / f)} -> false
// ([(a + b) + {(c + d) * (e / f)}] -> false

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    stack<char> st;
    for (char ch : str)
    {
        if (ch == '[' || ch == '{' || ch == '(')
        {
            st.push(ch);
            continue;
        }
        if (ch == ']')
        {
            if (st.top() != '[')
            {
                cout << "false \n";
                return 0;
            }
            else if (st.size() == 0)
            {
                cout << "false \n";
                return 0;
            }
            else
            {
                st.pop();
            }
        }
        if (ch == '}')
        {
            if (st.top() != '{')
            {
                cout << "false \n";
                return 0;
            }
            else if (st.size() == 0)
            {
                cout << "false \n";
                return 0;
            }
            else
            {
                st.pop();
            }
        }
        if (ch == ')')
        {
            if (st.top() != '(')
            {
                cout << "false\n";
                return 0;
            }
            else if (st.size() == 0)
            {
                cout << "false \n";
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.size() != 0)
    {
        cout << "false \n";
        return 0;
    }
    else
    {
        cout << "true\n";
        return 0;
    }
}
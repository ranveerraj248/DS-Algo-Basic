// 1. You are given a string exp representing an expression.
// 2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
// 3. But, some of the pair of brackets maybe extra/needless.
// 4. You are required to print true if you detect extra brackets and false otherwise.

// e.g.'
// ((a + b) + (c + d)) -> false
// (a + b) + ((c + d)) -> true

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            if (st.top() == '(')
            {
                cout << "true";
                return 0;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(str[i]);
        }
    }
    cout << "false" << endl;
    return 0;
}
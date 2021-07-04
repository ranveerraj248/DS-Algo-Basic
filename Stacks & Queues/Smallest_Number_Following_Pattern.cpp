// 1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
// 2. 'd' stands for decreasing and 'i' stands for increasing
// 3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that
// the digit decreases following a d and increases follwing an i.
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    stack<int> st;
    int count = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'd')
        {
            st.push(count++);
        }
        else
        {
            st.push(count++);
            while (st.size() > 0)
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    st.push(count);
    while (st.size() > 0)
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}
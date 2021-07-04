// 1. You are given a number n, representing the number of people in a party.
// 2. You are given n strings of n length containing 0's and 1's
// 3. If there is a '1' in ith row, jth spot, then person i knows about person j.
// 4. A celebrity is defined as somebody who knows no other person than himself but everybody else knows him.
// 5. If there is a celebrity print it's index otherwise print "none".
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        string str = "";
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() >= 2)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if (arr[i][j] == 1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }
    int potetialCeleb = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != potetialCeleb)
        {
            if ((arr[potetialCeleb][i] == 1 || arr[i][potetialCeleb] == 0))
            {
                cout << "none" << endl;
                return 0;
            }
        }
    }
    cout << potetialCeleb << endl;
    return 0;
}

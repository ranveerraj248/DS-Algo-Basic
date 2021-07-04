#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    stack<int> st;
    string str = "";
    int number;
    cin >> number;
    st.push(number);
    str += to_string(number);
    cout << str << endl;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        if (st.empty())
        {
            st.push(num);
            str += to_string(num);
            cout << str << endl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
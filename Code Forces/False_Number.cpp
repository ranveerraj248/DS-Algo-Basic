#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string A;
    cin >> A;
    if (A[0] == '1')
    {
        A.insert(1, "0");
    }
    else
    {
        A.insert(0, "1");
    }
    cout << A << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
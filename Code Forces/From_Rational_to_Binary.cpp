#include <bits/stdc++.h>
using namespace std;
typedef double lli;
void solve()
{
    lli a, b;
    cin >> a >> b;
    if (b == 2 || b == 4 || b == 5 || b == 8)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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
}
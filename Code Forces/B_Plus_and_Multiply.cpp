#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll temp = 1;
    if (a == 1)
    {
        if ((n - 1) % b == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    while (temp <= n)
    {
        if ((n - temp) % b == 0)
        {
            cout << "Yes\n";
            return;
        }
        temp *= a;
    }
    cout << "No\n";
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
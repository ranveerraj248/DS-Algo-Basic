#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    // cout << n / 9 << endl;
    if (n <= 8)
    {
        cout << "0" << endl;
    }
    else if (n <= 10)
    {
        cout << "1" << endl;
    }
    else if (n % 10 == 9)
    {
        ll count = n / 10;
        cout << count + 1 << endl;
    }
    else
    {
        cout << n / 10 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
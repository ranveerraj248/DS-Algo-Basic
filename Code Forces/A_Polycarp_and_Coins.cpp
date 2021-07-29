#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    ll c1, c2;
    c1 = n / 3;
    c2 = n / 3;
    if (n % 3 == 0)
    {
        cout << c1 << " " << c2 << endl;
    }
    else if (n % 3 == 1)
    {
        cout << c1 + 1 << " " << c2 << endl;
    }
    else
    {
        cout << c1 << " " << c2 + 1 << endl;
    }
}
int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
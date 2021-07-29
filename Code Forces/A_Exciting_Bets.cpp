#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll diff = abs(a - b);
    if (a == b)
    {
        cout << "0 0\n";
        return;
    }
    else
    {
        cout << diff << " " << min((a % diff), (abs((a - diff) % diff))) << "\n";
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
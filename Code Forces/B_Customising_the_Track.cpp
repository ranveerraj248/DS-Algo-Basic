#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for (auto &e : arr)
    {
        cin >> e;
        sum += e;
    }
    cout << (sum % n) * (n - (sum % n)) << endl;
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
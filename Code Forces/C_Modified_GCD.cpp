#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<ll> &fac)
{
    ll low, high;
    cin >> low >> high;
    ll res = -1;
    for (auto &e : fac)
    {
        if (e >= low && e <= high)
        {
            res = max(res, e);
        }
    }
    cout << res << endl;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    ll gcd = __gcd(a, b);
    vector<ll> factors;
    for (ll i = 1; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            factors.push_back(i);
            if (i * i != gcd)
            {
                factors.push_back(gcd / i);
            }
        }
    }
    ll n;
    cin >> n;
    while (n--)
    {
        solve(factors);
    }
    return 0;
}
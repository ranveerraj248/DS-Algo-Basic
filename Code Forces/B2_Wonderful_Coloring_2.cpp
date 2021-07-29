#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll paintCount(ll n, ll k, vector<ll> &arr)
{
    unordered_map<ll, ll> m;
    m.clear();
    for (ll i = 0; i < arr.size(); i++)
    {
        if (m.find(arr[i]) == m.end())
        {
            m.insert(make_pair(arr[i], 1));
        }
        else
        {
            m[arr[i]]++;
        }
    }
    ll c = 0;
    ll counter = 0;
    for (auto &it : m)
    {
        if (it.second >= k)
        {
            counter++;
        }
        else
        {
            c++;
        }
    }
    return counter + (c / k);
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &e : arr)
    {
        cin >> e;
    }
    ll paintCounter = paintCount(n, k, arr);
    cout << paintCounter;
    vector<pair<set<ll>, ll>> paint(k);
    for (ll i = 0; i < k; i++)
    {
        paint[i].second = paintCounter;
    }
    for (ll i = 0; i < n; i++)
    {
    }
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
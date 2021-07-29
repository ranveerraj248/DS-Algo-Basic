#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &e : a)
    {
        cin >> e;
    }
    for (int &e : b)
    {
        cin >> e;
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<ll> arr(m);
    for (ll &e : arr)
    {
        cin >> e;
    }
    ll initial = 1;
    ll time = 0;
    for (ll &e : arr)
    {

        if (e >= initial)
        {
            time += (ll)(e - initial);
        }
        else
        {
            time += (ll)(n - initial + e);
        }
        initial = e;
    }
    cout << time;
    return 0;
}
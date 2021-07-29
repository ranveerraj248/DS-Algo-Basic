#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> maxLeft(n + 2, 0LL);
    vector<ll> maxRight(n + 2, 0LL);

    for (ll i = 1; i <= n; i++)
    {
        if (i == 1 || arr[i] <= arr[i - 1])
        {
            maxLeft[i] = 1;
        }
        else
        {
            maxLeft[i] = 1 + maxLeft[i - 1];
        }
    }
    for (ll i = n; i >= 1; i--)
    {
        if (i == n || arr[i] >= arr[i + 1])
        {
            maxRight[i] = 1;
        }
        else
        {
            maxRight[i] = 1 + maxRight[i + 1];
        }
    }
    ll ans = 0;
    for (ll p = 1; p <= n; p++)
    {
        ans = max(ans, 1 + maxLeft[p - 1]);
        ans = max(ans, 1 + maxRight[p + 1]);
        if (arr[p + 1] - arr[p - 1] >= 2)
        {
            ans = max(ans, 1 + maxLeft[p - 1] + maxRight[p + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
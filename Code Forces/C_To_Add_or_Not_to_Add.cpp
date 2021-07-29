#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isok(ll i, ll j, ll k, vector<ll> &pre, ll val)
{
    ll cost = (i - j + 1) * val - (pre[i] - pre[j - 1]);
    return cost <= k;

    //hgjhg
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    arr[0] = INT_MIN;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    arr[0] = 0;
    vector<ll> pre(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    ll maxi = 1, ans = arr[1];
    for (ll i = 2; i <= n; i++)
    {
        ll low = 1, high = i, cnt;
        while ((high - low) > 1)
        {
            ll mid = (low + high) / 2;
            if (isok(i, mid, k, pre, arr[i]))
                high = mid;
            else
                low = mid + 1;
        }
        if (isok(i, low, k, pre, arr[i]))
            cnt = (i - low + 1);
        else
        {
            cnt = (i - high + 1);
        }
        if (cnt > maxi)
        {
            maxi = cnt;
            ans = arr[i];
        }
    }
    cout << maxi << " " << ans << endl;
}

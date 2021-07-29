#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<ll> arr(n);
    for (ll &e : arr)
    {
        cin >> e;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    vector<ll> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = arr[i - 1] + prefixSum[i - 1];
    }
    ll i = 1;
    ll sum = 0;
    while (i <= n)
    {
        sum += prefixSum[i];
        i *= 4;
    }
    cout << sum << endl;
    return 0;
}
// int main()
// {
//     int n;
//     long long s;
//     vector<int> a;
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> n;
//     a.resize(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//     }
//     sort(a.rbegin(), a.rend());
//     s = 0;
//     for (int m = 1; m <= n; m *= 4)
//     {
//         s += accumulate(a.begin(), a.begin() + m, 0LL);
//     }
//     cout << s << endl;

//     return 0;
// }
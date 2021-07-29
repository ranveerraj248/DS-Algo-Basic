#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> lastIndex;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        lastIndex[arr[i]] = i;
        }
    ll longest = min(n, 2LL);
    set<ll> aSet;
    for (ll i = 0; i < n; i++)
    {
        if (aSet.find(arr[i]) != aSet.end())
        {
            continue;
        }
        aSet.insert(arr[i]);
        ll A = arr[i];
        set<ll> bSet;
        for (ll j = i + 1; j < n; j++)
        {
            if (bSet.find(arr[j]) != bSet.end())
            {
                continue;
            }
            bSet.insert(arr[j]);
            ll B = arr[j];
            ll curLength = 2;
            ll k = j + 1;
            ll bound = max(lastIndex[A], lastIndex[B]);
            while (k <= bound)
            {
                if (arr[k] == A && (curLength % 2 == 0))
                {
                    curLength++;
                }
                else if (arr[k] == B && (curLength % 2 == 1))
                {
                    curLength++;
                }
                k++;
            }
            longest = max(longest, curLength);
        }
    }
    cout << longest;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct operation
{
    ll l;
    ll r;
    ll d;
    ll count = 0ll;
};
struct query
{
    ll x;
    ll y;
};
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<long long> arr(n);
    for (long long &e : arr)
    {
        cin >> e;
    }
    vector<operation> operations(m);
    for (auto &e : operations)
    {
        cin >> e.l;
        cin >> e.r;
        cin >> e.d;
    }
    vector<query> queries(k);
    for (auto &e : queries)
    {
        cin >> e.x;
        cin >> e.y;
    }

    for (auto &e : queries)
    {
        for (int i = e.x - 1; i < e.y; i++)
        {
            operations[i].count++;
        }
    }
    for (auto &e : operations)
    {
        if (e.count > 0)
        {
            ll D = (ll)(e.d * e.count);
            for (int i = e.l - 1; i < e.r; i++)
            {
                arr[i] += D;
            }
        }
    }
    // for (long long i = 0; i < k; i++)
    // {
    //     long long start = queries[i][0];
    //     long long end = queries[i][1];
    //     for (long long j = start - 1; j < end; j++)
    //     {
    //         long long idxStart = operations[j][0];
    //         long long idxEnd = operations[j][1];
    //         for (long long a = idxStart - 1; a < idxEnd; a++)
    //         {
    //             arr[a] += operations[j][2];
    //         }
    //     }
    // }
    for (long long &e : arr)
    {
        cout << e << " ";
    }
}
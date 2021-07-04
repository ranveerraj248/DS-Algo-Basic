#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll minRound;
    for (auto &e : arr)
    {
        cin >> e;
    }
    ll sum = 0;
    for (auto &e : arr)
    {
        sum += e;
    }
    minRound = *max_element(arr.begin(), arr.end());
    ll round = sum / n - 1;
    if (ceil((double)sum / (n - 1) < minRound))
        printf("%d\n", minRound);
    else
        printf("%d\n", (int)ceil((double)sum / (n - 1)));
    return 0;
}
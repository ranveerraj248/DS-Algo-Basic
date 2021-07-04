#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &e : arr)
    {
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs((i + 1) - arr[i]);
    }
    cout << ans;
}
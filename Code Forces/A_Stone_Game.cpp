#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    int minm = INT_MAX;
    int maxm = INT_MIN;
    int maxElementIndex = max_element(arr.begin(), arr.end()) - arr.begin() + 1;
    int minElementIndex = min_element(arr.begin(), arr.end()) - arr.begin() + 1;
    //cout << maxElementIndex << " " << minElementIndex << endl;
    int mid;
    if (n % 2 == 1)
    {
        mid = n / 2 + 1;
    }
    else
    {
        mid = n / 2;
    }
    if (maxElementIndex == mid || minElementIndex == mid)
    {

        if (n % 2 == 1)
        {
            cout << (n / 2) << endl;
        }
        else
        {
            cout << (n / 2) + 1 << endl;
        }
    }
    else if (maxElementIndex < (mid) && minElementIndex < (mid))
    {

        cout << max(minElementIndex, maxElementIndex) << endl;
    }
    else if (maxElementIndex > mid && minElementIndex > mid)
    {
        minm = n - minElementIndex + 1;
        maxm = n - maxElementIndex + 1;
        cout << max(minm, maxm) << endl;
    }
    else
    {
        if (maxElementIndex > minElementIndex)
        {
            maxElementIndex = n - maxElementIndex + 1;
        }
        else
        {
            minElementIndex = n - minElementIndex + 1;
        }

        cout << maxElementIndex + minElementIndex << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
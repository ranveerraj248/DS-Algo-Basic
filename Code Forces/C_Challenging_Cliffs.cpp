#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    for (int &e : arr)
    {
        cout << e << " ";
    }
    // vi ans(n);
    // arr[0] = ans[0];
    // arr[1] = ans[n - 1];
    // if (n > 2)
    // {
    //     int low = 2;
    //     int high = n - 1;
    //     int i = 1;
    //     while (low <= high && i != n - 1)
    //     {
    //         ans[high] = arr[i];
    //         i++;
    //         ans[low] = arr[i];
    //         i++;
    //     }
    // }
    // for (int &e : ans)
    // {
    //     cout << e << " ";
    // }
    cout << endl;
    return;
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
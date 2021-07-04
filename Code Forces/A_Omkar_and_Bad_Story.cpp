#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    bool flag = false;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
        if (e < 0)
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "NO" << endl;
        return;
    }

    int maxm = *max_element(arr.begin(), arr.end());
    if ((maxm + 1) > 300)
    {
        cout << "NO";
        cout << endl;
        return;
    }
    cout << "YES" << endl;
    cout << maxm + 1 << endl;

    for (int i = 0; i < maxm + 1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
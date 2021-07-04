#include <bits/stdc++.h>
using namespace std;
void solve()
{

    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
        sum += e;
    }
    if (sum < n)
    {
        cout << 1 << endl;
        return;
    }
    cout << (abs(sum) - n) << endl;
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
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for (int &e : arr)
    {
        cin >> e;
    }
    int odd = 0;
    int even = 0;
    for (int &e : arr)
    {
        if (e % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (even == odd)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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
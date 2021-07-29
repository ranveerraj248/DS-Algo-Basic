#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x[4], y[4];
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];
    cin >> x[3] >> y[3];
    int ans = 0;
    bool flag = false;
    if ((x[1] == x[2] && x[2] == x[3]))
    {
        if (y[1] < y[3] && y[2] > y[3])
            flag = true;
        if (y[2] < y[3] && y[1] > y[3])
            flag = true;
    }
    if ((y[1] == y[2] && y[2] == y[3]))
    {
        if (x[1] < x[3] && x[2] > x[3])
            flag = true;
        if (x[2] < x[3] && x[1] > x[3])
            flag = true;
    }
    ans += abs(x[1] - x[2]) + abs(y[1] - y[2]);
    if (flag)
    {
        ans += 2;
    }
    cout << ans << endl;
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
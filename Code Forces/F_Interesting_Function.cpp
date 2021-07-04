#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli low, high;
    cin >> low;
    cin >> high;
    auto ans = [](lli initial)
    {
        lli answere = 0;
        int temp = initial;
        while (temp)
        {
            answere += temp;
            temp /= 10;
        }
        return answere;
    };
    cout << ans(high) - ans(low) << endl;
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
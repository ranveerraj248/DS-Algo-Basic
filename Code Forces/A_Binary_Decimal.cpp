#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    ll count = 0;
    while (n > 0)
    {
        ll variable = n;
        ll newNo = 0;
        ll set = 1;
        while (variable)
        {
            ll digit = variable % 10;
            variable /= 10;
            if (digit != 0)
            {
                newNo += set;
            }
            set *= 10;
        }
        count++;
        n -= newNo;
    }
    cout << count << endl;
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
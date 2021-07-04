#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    //n = n % mod;
    ll even, odd;
    if (n % 2 == 0)
    {
        even = (n / 2) % mod;
        odd = (n / 2) % mod;
    }
    else
    {
        even = (n / 2) % mod;
        odd = ((n / 2) % mod) + 1;
    }
    ll div6 = 0;
    div6 = (n / 6) % mod;
    even -= div6;
    ll ans5 = (div6 / 2) * 5;
    ll ans4 = (div6 - (div6 / 2)) * 4;
    cout << (even * 3 + odd * 2 + ans5 + ans4) % mod << endl;
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
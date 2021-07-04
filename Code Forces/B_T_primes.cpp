#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
bool isPrime(lli n)
{

    if (n <= 1)
    {
        return false;
    }
    else if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    if (n % 3 == 0)
    {
        return false;
    }
    for (int j = 5; j <= sqrt(n); j += 6)
    {
        if (n % j == 0 || n % (j + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    lli n;
    cin >> n;
    long long sqr = sqrt(n);
    if ((sqr * sqr == n) && isPrime(sqrt(n)))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
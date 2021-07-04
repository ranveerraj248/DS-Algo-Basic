#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void solve()
{
    int n;
    cin >> n;
    vi temp(n, -1);
    int even = 4;
    int odd = 1;
    temp[0] = 2;
    if (n == 3)
    {
        cout << ("3 1 2") << endl;
        return;
    }
    int range;
    if (n % 2 == 0)
    {
        range = n;
    }
    else
    {
        range = n - 2;
        temp[n - 2] = n;
        temp[n - 1] = n - 2;
    }
    for (int i = 1; i < range; i++)
    {
        if (i % 2 == 0)
        {
            temp[i] = even;
            even += 2;
        }
        else
        {
            temp[i] = odd;
            odd += 2;
        }
    }

    for (int &e : temp)
    {
        cout << e << " ";
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
    return 0;
}
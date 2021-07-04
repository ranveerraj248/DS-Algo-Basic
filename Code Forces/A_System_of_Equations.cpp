#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int a = 0; a <= m && a * a <= n; a++)
    {

        int b = n - (a * a);
        if (a + (b * b) == m)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
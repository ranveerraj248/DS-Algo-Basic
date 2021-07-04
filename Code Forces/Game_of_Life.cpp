#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    string arr;
    cin >> arr;
    if (n == 1)
    {
        cout << arr;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        string temp = arr;
        for (int j = 0; j < n; j++)
        {
            if (j == 0 && arr[0] == '0' && arr[1] == '1')
            {
                temp[0] = '1';
                continue;
            }
            if (j == n - 1 && arr[j] == '0' && arr[j - 1] == '1')
            {
                temp[j] = '1';
                continue;
            }
            if (arr[j] == '0' && ((arr[j - 1] == '1' && arr[j + 1] == '0') || (arr[j - 1] == '0' && arr[j + 1] == '1')))
            {
                temp[j] = '1';
            }
        }
        if (temp == arr)
        {
            break;
        }
        else
        {
            arr = temp;
        }
    }
    cout << arr;
    cout << endl;
    return;
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
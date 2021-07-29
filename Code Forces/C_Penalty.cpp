#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string str;
    cin >> str;
    int max1 = 0;
    int max2 = 0;
    int min1 = 0;
    int min2 = 0;
    int count = 0;
    int moveFirst = 5;
    int moveSecond = 5;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0 || i % 2 == 0)
        {
            if (str[i] == '1')
            {
                max1++;
                min1++;
            }
            else if (str[i] == '?')
            {
                max1++;
            }
            moveFirst--;
        }
        else
        {
            if (str[i] == '1')
            {
                max2++;
                min2++;
            }
            else if (str[i] == '?')
            {
                max2++;
            }
            moveSecond--;
        }
        count++;
        if (max1 > (min2 + moveSecond) || max2 > (min1 + moveFirst))
        {
            break;
        }
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string str;
    cin >> str;
    int longest0 = 0;
    int longest1 = 0;
    int cur0 = 0;
    int cur1 = 0;
    int i = 0;
    while (i < str.length())
    {

        if (str[i] == '1')
        {
            while (str[i] == '1' && i < str.length())
            {
                cur1++;
                i++;
            }
            if (cur1 > longest1)
            {
                longest1 = cur1;
            }
            cur1 = 0;
        }
        //ch = str[i];
        if (str[i] == '0')
        {
            while (str[i] == '0' && i < str.length())
            {
                cur0++;
                i++;
            }
            if (cur0 > longest0)
            {
                longest0 = cur0;
            }
            cur0 = 0;
        }
    }
    if (longest1 > longest0)
    {
        //cout << longest0 << " " << longest1 << endl;
        cout << true << endl;
    }
    else
    {
        //cout << longest0 << " " << longest1 << endl;
        cout << false << endl;
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
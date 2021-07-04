#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string str;
    cin >> str;
    if (str.size() <= 3)
    {
        cout << "Error\n";
        return;
    }
    bool flag = true;
    if (str[0] == '<' && str[1] == '/' && str[str.size() - 1] == '>')
    {
        for (int i = 2; i < str.size() - 1; i++)
        {
            if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        cout << "Error\n";
        return;
    }
    if (flag)
    {
        cout << "Success\n";
    }
    else
    {
        cout << "Error\n";
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
}
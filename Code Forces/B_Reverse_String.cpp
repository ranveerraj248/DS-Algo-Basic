#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    int i = 0;
    int j = 0;
    size_t found = str1.find(str2[j]);
    if (found != string::npos)
    {
        i = found;
        while (i < str1.size() && j < str2.size() && str1[i] == str2[j])
        {
            i++;
            j++;
        }
        if (j == str2.size())
        {
            cout << "YES\n";
            return;
        }
        i -= 2;
        while (i >= 0 && j < str2.size() && str1[i] == str2[j])
        {
            i--;
            j++;
        }
        if (j == str2.size())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "NO\n";
    }
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
}
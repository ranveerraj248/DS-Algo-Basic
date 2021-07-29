#include <bits/stdc++.h>
using namespace std;
string reff = "abcdefghijklmnopqrstuvwxyz";
void solve()
{
    string str;
    cin >> str;
    string temp = str;
    sort(temp.begin(), temp.end());
    string reference = reff.substr(0, str.size());
    if (temp != reference)
    {
        cout << "NO\n";
        return;
    }
    for (int i = str.size() - 1; i >= 0; i--)
    {
        char ch = reff[i];
        int n = str.size() - 1;
        if (ch == str[0] || ch == str[n])
        {
            if (ch == str[0])
            {
                str.erase(str.begin() + 0);
            }
            else
            {
                str.erase(str.begin() + n);
            }
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
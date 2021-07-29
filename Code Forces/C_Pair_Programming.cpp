#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void solve()
{
    int k, n, m;
    cin >> k >> n >> m;
    vi ploy(n);
    vi mono(m);
    for (auto &e : ploy)
    {
        cin >> e;
    }
    for (auto &e : mono)
    {
        cin >> e;
    }
    int i = 0;
    int j = 0;
    string ans = "";
    bool flag = false;
    while ((i < n) && (j < m))
    {
        if (ploy[i] == 0)
        {
            ans += to_string(ploy[i]) + " ";
            k++;
            i++;
        }
        else if (mono[j] == 0)
        {
            ans += to_string(mono[j]) + " ";
            k++;
            j++;
        }
        else if (ploy[i] <= k)
        {
            ans += to_string(ploy[i]) + " ";
            i++;
        }
        else if (mono[j] <= k)
        {
            ans += to_string(mono[j]) + " ";
            j++;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    while (i < n)
    {
        if (ploy[i] == 0)
        {
            ans += to_string(ploy[i]) + " ";
            k++;
            i++;
        }
        else if (ploy[i] <= k)
        {
            ans += to_string(ploy[i]) + " ";
            i++;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    while (j < m)
    {
        if (mono[j] == 0)
        {
            ans += to_string(mono[j]) + " ";
            k++;
            j++;
        }
        else if (mono[j] <= k)
        {
            ans += to_string(mono[j]) + " ";
            j++;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans << endl;
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
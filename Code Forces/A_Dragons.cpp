#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, n;
    cin >> s >> n;
    pair<int, int> dragons[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> dragons[i].first >> dragons[i].second;
    }
    sort(dragons, dragons + n);
    int flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s <= dragons[i].first)
        {
            flag = false;
            break;
        }
        else
        {
            s += dragons[i].second;
        }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
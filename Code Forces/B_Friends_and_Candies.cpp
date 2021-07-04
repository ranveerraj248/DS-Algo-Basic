#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[0] != arr[i])
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "0" << endl;
        return;
    }
    int sum = 0;
    for (int &e : arr)
    {
        sum += e;
    }
    if (sum % n != 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        int higher = sum / n;
        int count = 0;
        for (int &e : arr)
        {
            if (e > higher)
            {
                count++;
            }
        }
        cout << count << endl;
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
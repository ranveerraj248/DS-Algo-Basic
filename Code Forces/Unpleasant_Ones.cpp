#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> even, odd;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
        if (e % 2 == 0)
        {
            even.push_back(e);
        }
        else
        {
            odd.push_back(e);
        }
    }
    for (int &e : even)
    {
        cout << e << " ";
    }
    sort(odd.begin(), odd.end(), greater<int>());
    for (int &e : odd)
    {
        cout << e << " ";
    }
    cout << endl;
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
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    map<int, int> mymap;
    int index = 1;
    for (int &e : arr)
    {
        mymap.insert(make_pair(e, index));
        index++;
    }
    int count = 0;
    for (auto &e : mymap)
    {
        for (int j = 1; j <= sqrt(e.first); j++)
        {
            if (e.first % j == 0 && e.first != j * j)
            {
                if (mymap[j] + mymap[e.first / j] == e.first)
                {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
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
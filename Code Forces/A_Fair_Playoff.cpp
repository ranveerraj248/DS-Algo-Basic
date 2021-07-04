#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void solve()
{
    vi s(4);

    for (int &e : s)
    {
        cin >> e;
    }
    int largest = *max_element(s.begin(), s.end());
    int secondLargest = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        if (s[i] != largest)
        {
            if (s[i] > secondLargest)
            {
                secondLargest = s[i];
            }
        }
    }
    int firstMatch = max(s[0], s[1]);
    int secondMatch = max(s[2], s[3]);

    if ((firstMatch == largest || firstMatch == secondLargest) && (secondMatch == largest || secondMatch == secondLargest))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
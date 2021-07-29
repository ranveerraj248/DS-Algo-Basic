#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string str;
    cin >> str;
    vector<int> freqArr(26, 0);
    for (char ch : str)
    {
        freqArr[ch - 'a'] += 1;
    }
    int multiple = 0;
    int single = 0;
    for (int &e : freqArr)
    {
        if (e >= 2)
        {
            multiple++;
        }
        else if (e != 0)
        {
            single++;
        }
    }
    cout << multiple + (single / 2) << endl;
}
int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> cupboards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cupboards[i].first;
        cin >> cupboards[i].second;
    }
    int l0 = 0, l1 = 0, r0 = 0, r1 = 0;
    for (auto doors : cupboards)
    {
        if (doors.first == 1)
            l1++;
        else
            l0++;
        if (doors.second == 1)
            r1++;
        else
            r0++;
    }
    int result = min(l0, l1) + min(r0, r1);
    cout << result;
    return 0;
}
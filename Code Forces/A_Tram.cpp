#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> passanger(n);
    for (auto &passenger : passanger)
    {
        cin >> passenger.first;
        cin >> passenger.second;
    }
    int cap = 0;
    int curr = 0;
    for (auto &stop : passanger)
    {
        curr = (curr - stop.first) + stop.second;
        cap = max(cap, curr);
    }
    cout << cap;
}
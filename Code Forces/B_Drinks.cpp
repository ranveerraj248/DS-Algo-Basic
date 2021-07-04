#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << fixed;
    cout << setprecision(12);
    cout << sum / n;
    return 0;
}
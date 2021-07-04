#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vl;
typedef vector<vl> vll;
int lis(vl &arr, int n)
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

int main()
{
    ll n;
    cin >> n;
    vl arr(n);
    for (auto &e : arr)
    {
        cin >> e;
    }
    vll dp(n, (vl(n, 0)));
    cout << lis(arr, n);
    return 0;
}
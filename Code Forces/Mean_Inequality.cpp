// You are given an array a of 2n distinct integers. You want to arrange the elements of the array in a circle such that no element is equal to the the arithmetic mean of its 2 neighbours.

// More formally, find an array b, such that:

// b is a permutation of a.

// For every i from 1 to 2n, bi≠bi−1+bi+12, where b0=b2n and b2n+1=b1.

// It can be proved that under the constraints of this problem, such array b always exists.

// Input
// The first line of input contains a single integer t (1≤t≤1000) — the number of testcases. The description of testcases follows.

// The first line of each testcase contains a single integer n (1≤n≤25).

// The second line of each testcase contains 2n integers a1,a2,…,a2n (1≤ai≤109) — elements of the array.

// Note that there is no limit to the sum of n over all testcases.

// Output
// For each testcase, you should output 2n integers, b1,b2,…b2n, for which the conditions from the statement are satisfied.
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    n = n * 2;
    int a[55];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n / 2; i += 2)
    {
        swap(a[i], a[n + 1 - i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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
    return 0;
}
// Given an integer n, find the maximum value of integer k such that the following condition holds:

// n & (n−1) & (n−2) & (n−3) & ... (k) = 0
// where & denotes the bitwise AND operation.
// Input
// The first line contains a single integer t (1≤t≤3⋅104). Then t test cases follow.

// The first line of each test case contains a single integer n (1≤n≤109).

// Output
// For each test case, output a single integer — the required integer k.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = 0;
        int ans = 1;
        while (true)
        {
            k = n - 1;
            n = n & k;
            if (n == 0)
            {
                break;
            }
            k--;
        }
        cout << k << endl;
    }
}
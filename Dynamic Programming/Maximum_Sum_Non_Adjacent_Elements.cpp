// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers, representing n elements.
// 3. You are required to find the maximum sum of a subsequence with no adjacent elements.
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
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = arr[0];
    dp[1][0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[1][i - 1] + arr[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]);
    return 0;
}
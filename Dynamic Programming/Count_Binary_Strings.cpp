// 1. You are given a number n.
// 2. You are required to print the number of binary strings of length n with no consecutive 0's.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    }
    cout << dp[0][n] + dp[1][n];
}
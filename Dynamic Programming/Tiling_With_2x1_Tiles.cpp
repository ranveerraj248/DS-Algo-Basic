// 1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
// 2. You've an infinite supply of 2 * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.
#include <iostream>
#include <vector>
using namespace std;
int tilingWays(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    cout << tilingWays(n);
    return 0;
}
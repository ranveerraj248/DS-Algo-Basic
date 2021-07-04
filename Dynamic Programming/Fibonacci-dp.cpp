#include <iostream>
#include <vector>
using namespace std;

int fibMemoized(int n, vector<int> dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int fib1 = fibMemoized(n - 1, dp);
    int fib2 = fibMemoized(n - 2, dp);
    int fibn = fib1 + fib2;

    dp[n] = fibn;

    return fibn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    fill(dp.begin(), dp.end(), 0);
    cout << fibMemoized(n, dp) << endl;
    return 0;
}
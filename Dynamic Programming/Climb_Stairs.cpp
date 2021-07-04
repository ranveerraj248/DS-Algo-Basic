// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. In one move, you are allowed to climb 1, 2 or 3 stairs.
// 4. You are required to print the number of different paths via which you can climb to the top.
#include <iostream>
#include <vector>
using namespace std;

int cs(int n, vector<int> dp)
{

    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int c1 = cs(n - 1, dp);
    int c2 = cs(n - 2, dp);
    int c3 = cs(n - 3, dp);

    int result = c1 + c2 + c3;
    dp[n] = result;
    return result;
}
int csTab(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            dp[i] = dp[i - 1];
        }
        else if (i == 2)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    fill(dp.begin(), dp.end(), 0);
    cout << csTab(n) << endl;
}
// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without
//      overflowing it's capacity.

// Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item
//                again and again.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> value(n);
    for (int &e : value)
    {
        cin >> e;
    }
    vector<int> weight(n);
    for (int &e : weight)
    {
        cin >> e;
    }
    int maxWeight;
    cin >> maxWeight;
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - weight[i - 1]] + value[i - 1]));
            }
        }
    }
    cout << dp[n][maxWeight];
    return 0;
}
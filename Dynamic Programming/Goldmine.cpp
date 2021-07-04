// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
// 4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from
//      any row in the left wall.
// 5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug out from the mine.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + arr[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j + 1], max(dp[i][j + 1], dp[i + 1][j + 1])) + arr[i][j];
            }
        }
    }
    int maxm = dp[0][0];
    for (int i = 0; i < n; i++)
    {
        maxm = max(maxm, dp[i][0]);
    }
    cout << maxm;
}
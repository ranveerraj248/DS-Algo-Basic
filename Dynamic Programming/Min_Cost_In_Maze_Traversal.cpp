// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.
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
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            }
            else if (j == m - 1)
            {
                dp[i][j] = dp[i + 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + arr[i][j];
            }
        }
    }
    cout << dp[0][0];
    return 0;
}
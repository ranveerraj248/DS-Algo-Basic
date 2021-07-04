// 1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
// 2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<vector<int>> arr(n, vector<int>(c));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<long long>> dp(n, vector<long long>(c));
    long long least = INT_MAX;
    long long sLeast = INT_MAX;
    for (int j = 0; j < c; j++)
    {
        dp[0][j] = arr[0][j];

        if (arr[0][j] <= least)
        {
            sLeast = least;
            least = arr[0][j];
        }
        else
        {
            sLeast = arr[0][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        long long nLeast = INT_MAX;
        long long nsLeast = INT_MAX;
        for (int j = 0; j < c; j++)
        {
            if (least == dp[i - 1][j])
            {
                dp[i][j] = 1LL * (sLeast + arr[i][j]);
            }
            else
            {
                dp[i][j] = 1LL * (least + arr[i][j]);
            }

            if (dp[i][j] <= nLeast)
            {
                nsLeast = nLeast;
                nLeast = dp[i][j];
            }
            else
            {
                nsLeast = dp[i][j];
            }
        }
        least = nLeast;
        sLeast = nsLeast;
    }
    cout << least;
    return 0;
}
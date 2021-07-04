// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you
//      could jump to in a single move.  You can of-course fewer number of steps in the move.
// 4. You are required to print the number of minimum moves in which you can reach the top of
//      staircase.
// Note -> If there is no path through the staircase print null.
// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you
//      could jump to in a single move.
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can climb to the top.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n + 1);
    fill(dp.begin(), dp.end(), -1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            int minm = INT_MAX;
            for (int j = 1; j <= arr[i] && i + j < n + 1; j++)
            {
                if (dp[i + j] != -1)
                {

                    minm = min(minm, dp[i + j]);
                }
            }
            if (minm != INT_MAX)
            {

                dp[i] = minm + 1;
            }
        }
    }
    cout << dp[0] << endl;
}
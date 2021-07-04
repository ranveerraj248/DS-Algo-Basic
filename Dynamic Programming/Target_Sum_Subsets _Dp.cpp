// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. You are required to calculate and print true or false, if there is a subset the elements of which add
//      up to "tar" or not.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
            else
            {
                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    int val = arr[i - 1];
                    if (j >= val)
                    {
                        if (dp[i - 1][j - val] == true)
                        {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    if (dp[n][target])
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
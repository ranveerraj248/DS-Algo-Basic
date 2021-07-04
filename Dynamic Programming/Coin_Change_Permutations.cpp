// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the number of permutations of the n coins using which the
//      amount "amt" can be paid.

// Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be
//                   used for many installments in payment of "amt"
// Note2 -> You are required to find the count of permutations and not combinations i.e.
//                   2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same
//                   combination. You should treat them as 3 and not 1.
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
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int amt = 1; amt <= target; amt++)
    {
        for (int coin : arr)
        {
            if (coin <= amt)
            {
                int remAmt = amt - coin;
                dp[amt] += dp[remAmt];
            }
        }
    }
    cout << dp[target];
    return 0;
}
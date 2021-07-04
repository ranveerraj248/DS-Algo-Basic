// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without
//     overflowing it's capacity.
// Note -> Each item can be taken any number of times. You are allowed to put the same item again
//                   and again.
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
    vector<int> dp(maxWeight + 1);
    dp[0] = 0;
    for (int cap = 1; cap <= maxWeight; cap++)
    {
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= cap)
            {
                int remBagWeight = cap - weight[i];
                int remBagValue = dp[remBagWeight];
                int totalBagValue = value[i] + remBagValue;

                if (totalBagValue > max)
                {
                    max = totalBagValue;
                }
            }
        }
        dp[cap] = max;
    }
    cout << dp[maxWeight];
    return 0;
}
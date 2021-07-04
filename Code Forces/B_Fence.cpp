#include <bits/stdc++.h>
using namespace std;
int minSum(vector<int> &arr, int n, int k)
{
    // k must be greater
    if (n < k)
    {
        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size k
    int res = 0;
    int temp = 1;
    int ans = 1;
    for (int i = 0; i < k; i++)
        res += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int curr_sum = res;
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        temp++;
        if (curr_sum < res)
        {
            res = curr_sum;
            ans = temp;
        }
        //res = min(res, curr_sum);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    cout << minSum(arr, arr.size(), k);
    return 0;
}
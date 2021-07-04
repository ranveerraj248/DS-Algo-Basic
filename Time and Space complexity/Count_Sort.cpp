// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using count sort.

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void countSort(int arr[], int n, int min, int max)
{
    int range = max - min + 1;
    int freqArr[range] = {0};

    for (int i = 0; i < n; i++)
    {
        int idx = arr[i] - min;
        freqArr[idx]++;
    }
    for (int i = 1; i < range; i++)
    {
        freqArr[i] = freqArr[i] + freqArr[i - 1];
    }
    int ans[n];

    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = freqArr[val - min];
        int idx = pos - 1;
        ans[idx] = val;
        freqArr[val - min]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int minm = INT_MAX;
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    maxm = *max_element(arr, arr + n);
    minm = *min_element(arr, arr + n);
    countSort(arr, n, minm, maxm);
    print(arr, n);
    return 0;
}
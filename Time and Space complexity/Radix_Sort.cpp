// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using radix sort.

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int arr[], int n, int exp)
{
    int range = 10;
    int freqArr[range] = {0};
    int ans[n];

    for (int i = 0; i < n; i++)
    {
        freqArr[arr[i] / exp % 10]++;
    }
    for (int i = 1; i < range; i++)
    {
        freqArr[i] = freqArr[i] + freqArr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = freqArr[arr[i] / exp % 10];
        int idx = pos - 1;
        ans[idx] = arr[i];
        freqArr[arr[i] / exp % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }

    cout << "After sorting on " << exp << " place -> ";
    print(arr, n);
}

void radixSort(int arr[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int exp = 1;
    while (exp <= max)
    {
        countSort(arr, n, exp);
        exp = exp * 10;
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
    radixSort(arr, n);
    print(arr, n);
    return 0;
}
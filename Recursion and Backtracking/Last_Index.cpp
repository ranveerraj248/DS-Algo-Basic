// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number x.
// 4. You are required to find the last index at which x occurs in array a.
// 5. If x exists in array, print the last index where it is found otherwise print -1.

#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n)
{
    int index = -1;
    if (idx == n)
    {
        return -1;
    }
    index = lastIndex(arr, idx + 1, x, n);
    if (index == -1 && arr[idx] == x)
    {
        index = idx;
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}
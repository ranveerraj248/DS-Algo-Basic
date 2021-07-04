// 1. You are given an array(arr) of distinct integers, which is sorted and rotated around an unknown point.
// 2. You have to find the smallest element in O(logN) time-complexity

#include <iostream>
using namespace std;
int findPivot(int arr[], int n)
{

    int lo = 0;
    int hi = n - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] < arr[hi])
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return arr[hi];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pivot = findPivot(arr, n);
    cout << pivot;
    return 0;
}
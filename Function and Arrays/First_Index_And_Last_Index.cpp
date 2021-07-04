// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.

// Asssumption - Array is sorted. Array may have duplicate values.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int data;
    cin >> data;

    int low = 0;
    int high = n - 1;
    int first_index = -1;
    int last_index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data < arr[mid])
        {
            high = mid - 1;
        }
        else if (data > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            last_index = mid;
            low = mid + 1;
        }
    }
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data < arr[mid])
        {
            high = mid - 1;
        }
        else if (data > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            first_index = mid;
            high = mid - 1;
        }
    }
    cout << first_index << endl;
    cout << last_index << endl;
}
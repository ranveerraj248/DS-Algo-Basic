// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are given a number k.
// 4. Rotate the array a, k times to the right (for positive values of k), and to
// the left for negative values of k.

#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int *arr, int n, int k)
{

    k = k % n;
    if (k < 0)
    {
        k = k + n;
    }
    reverse(arr, arr + n - k);
    reverse(arr + n - k, arr + n);
    reverse(arr, arr + n);
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, r;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> r;

    rotate(arr, n, r);
    display(arr, n);
}
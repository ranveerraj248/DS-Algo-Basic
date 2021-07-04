// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to reverse the contents of array a.

#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int *arr, int n)
{
    for (int low = 0, high = n - 1; low < high; low++, high--)
    {
        swap(arr[low], arr[high]);
    }
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
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, n);
    display(arr, n);
}
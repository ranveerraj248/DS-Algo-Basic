// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using bubble sort.

// used for swapping ith and jth elements of array
#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// return true if ith element is smaller than jth element
bool isSmaller(int arr[], int i, int j)
{
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    if (arr[i] < arr[j])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bubbleSort(int arr[], int n)
{

    for (int itr = 1; itr <= n - 1; itr++)
    {
        for (int j = 0; j < n - itr; j++)
        {
            if (isSmaller(arr, j + 1, j))
            {
                swap(arr, j + 1, j);
            }
        }
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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    print(arr, n);
}
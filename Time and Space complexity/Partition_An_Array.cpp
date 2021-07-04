// 1. You are given an array(arr) of integers and a pivot.
// 2. You have to re-arrange the given array in such a way that all elements smaller or equal to pivot lie on the left side of pivot and all elements greater than pivot lie on its right side.
// 3. You have to achieve this in linear time.

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void partition(int arr[], int n, int pivot)
{
    // 0 to j - 1 ->   <= pivot
    // j to i - 1 ->   > pivot
    // i to end ->      unknown
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (arr[i] > pivot)
        {
            i++;
        }
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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

    int pivot;
    cin >> pivot;
    partition(arr, n, pivot);

    print(arr, n);
}
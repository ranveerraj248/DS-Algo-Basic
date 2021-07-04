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

void selectionSort(int arr[], int n)
{

    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (isSmaller(arr, j, min))
            {
                min = j;
            }
        }
        swap(arr, i, min);
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

    selectionSort(arr, n);

    print(arr, n);
}
// 1. You are given a number n, representing the number of rows and number of columns.
// 2. You are given n*n numbers, representing elements of 2d array a.
// 3. You are required to rotate the matrix by 90 degree clockwise and then display the contents using display function.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // transpose of an array
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse each column to rotate in clockwise direction
    for (int i = 0; i < n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
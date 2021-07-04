// 1. You are given a square matrix of size 'n'. You are given n*n elements of the square matrix.
// 2. You are required to find the saddle price of the given matrix and print the saddle price.
// 3. The saddle price is defined as the least price in the row but the maximum price in the column of the matrix.

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int svj = 0;
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] < arr[i][svj])
            {
                svj = j;
            }
        }
        bool flag = true;
        for (int k = 0; k < n; k++)
        {
            if (arr[k][svj] > arr[i][svj])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << arr[i][svj] << endl;
            return 0;
        }
    }
    cout << "Invalid input" << endl;
    return 0;
}
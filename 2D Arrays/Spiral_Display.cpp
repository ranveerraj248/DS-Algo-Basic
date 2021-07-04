// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a.
// 4. You are required to traverse and print the contents of the 2d array in form of a spiral.
// Note - Please check the sample output for details.
#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int row_start = 0;
    int col_start = 0;
    int row_end = n - 1;
    int col_end = m - 1;
    int totalElemnts = n * m;
    int curElement = 0;
    while (curElement < totalElemnts)
    {
        //   |
        //   | going down
        //  \ /
        for (int i = row_start; i <= row_end && curElement < totalElemnts; i++)
        {
            cout << arr[i][col_start] << endl;
            curElement++;
        }
        col_start++;
        //
        //  ---- > going left to right
        //
        for (int i = col_start; i <= col_end && curElement < totalElemnts; i++)
        {
            cout << arr[row_end][i] << endl;
            curElement++;
        }
        row_end--;
        //  ^
        //  | going up
        //  |
        for (int i = row_end; i >= row_start && curElement < totalElemnts; i--)
        {
            cout << arr[i][col_end] << endl;
            curElement++;
        }
        col_end--;
        //
        //  <--- going right to left
        //
        for (int i = col_end; i >= col_start && curElement < totalElemnts; i--)
        {
            cout << arr[row_start][i] << endl;
            curElement++;
        }
        row_start++;
    }
    return 0;
}